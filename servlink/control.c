/************************************************************************
 *   IRC - Internet Relay Chat, servlink/servlink.c
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */

#include "stdinc.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/evp.h>
#include <openssl/err.h>
#endif
#ifdef HAVE_LIBZ
#include <zlib.h>
#endif

#include "servlink.h"
#include "io.h"
#include "control.h"

static cmd_handler cmd_set_zip_out_level;
static cmd_handler cmd_start_zip_out;
static cmd_handler cmd_start_zip_in;
static cmd_handler cmd_set_crypt_in_cipher;
static cmd_handler cmd_set_crypt_in_key;
static cmd_handler cmd_start_crypt_in;
static cmd_handler cmd_set_crypt_out_cipher;
static cmd_handler cmd_set_crypt_out_key;
static cmd_handler cmd_start_crypt_out;
static cmd_handler cmd_init;
 
struct command_def command_table[] =
  {
    {    CMD_SET_ZIP_OUT_LEVEL,    cmd_set_zip_out_level, COMMAND_FLAG_DATA },
    {        CMD_START_ZIP_OUT,        cmd_start_zip_out,                 0 },
    {         CMD_START_ZIP_IN,         cmd_start_zip_in,                 0 },
    {  CMD_SET_CRYPT_IN_CIPHER,  cmd_set_crypt_in_cipher, COMMAND_FLAG_DATA },
    {     CMD_SET_CRYPT_IN_KEY,     cmd_set_crypt_in_key, COMMAND_FLAG_DATA },
    {       CMD_START_CRYPT_IN,       cmd_start_crypt_in,                 0 },
    { CMD_SET_CRYPT_OUT_CIPHER, cmd_set_crypt_out_cipher, COMMAND_FLAG_DATA },
    {    CMD_SET_CRYPT_OUT_KEY,    cmd_set_crypt_out_key, COMMAND_FLAG_DATA },
    {      CMD_START_CRYPT_OUT,      cmd_start_crypt_out,                 0 },
    {         CMD_INJECT_RECVQ,            process_recvq, COMMAND_FLAG_DATA },
    {         CMD_INJECT_SENDQ,            process_sendq, COMMAND_FLAG_DATA },
    {                 CMD_INIT,                 cmd_init,                 0 },
    {             CMD_ZIPSTATS,            send_zipstats,                 0 },
    {                        0,                        0,                 0 }
  };

void
cmd_set_zip_out_level(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBZ
  out_state.zip_state.level = *cmd->data;
  if ((out_state.zip_state.level < -1) ||
      (out_state.zip_state.level > 9))
    send_error("invalid compression level %d",
               out_state.zip_state.level);
#else
  send_error("can't set compression level - no libz support!");
#endif
}

void
cmd_start_zip_out(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBZ
  int ret;

  if (out_state.zip)
    send_error("can't start compression - already started!");

  out_state.zip_state.stream.total_in = 0;
  out_state.zip_state.stream.total_out = 0;
  out_state.zip_state.stream.zalloc = (alloc_func)0;
  out_state.zip_state.stream.zfree = (free_func)0;
  out_state.zip_state.stream.data_type = Z_ASCII;

  if (out_state.zip_state.level <= 0)
    out_state.zip_state.level = Z_DEFAULT_COMPRESSION;

  if ((ret = deflateInit(&out_state.zip_state.stream,
                         out_state.zip_state.level)) != Z_OK)
    send_error("deflateInit failed: %d (%s)", ret, zError(ret));

  out_state.zip = 1;
#else
  send_error("can't start compression - no libz support!");
#endif
}

void
cmd_start_zip_in(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBZ
  int ret;

  if (in_state.zip)
    send_error("can't start decompression - already started!");

  in_state.zip_state.stream.total_in = 0;
  in_state.zip_state.stream.total_out = 0;
  in_state.zip_state.stream.zalloc = (alloc_func)0;
  in_state.zip_state.stream.zfree = (free_func)0;
  in_state.zip_state.stream.data_type = Z_ASCII;
  if ((ret = inflateInit(&in_state.zip_state.stream)) != Z_OK)
    send_error("inflateInit failed: %d (%s)", ret, zError(ret));
  in_state.zip = 1;
#else
  send_error("can't start decompression - no libz support!");
#endif
}

void
cmd_set_crypt_in_cipher(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBCRYPTO
  unsigned int cipher = *cmd->data;

  if (in_state.crypt_state.cipher)
    send_error("can't set decryption cipher - already set!");

  switch (cipher)
  {
#ifdef HAVE_EVP_BF_CFB
    case CIPHER_BF:
      in_state.crypt_state.cipher = EVP_bf_cfb();
      break;
#endif
#ifdef HAVE_EVP_CAST5_CFB
    case CIPHER_CAST:
      in_state.crypt_state.cipher = EVP_cast5_cfb();
      break;
#endif
#ifdef HAVE_EVP_DES_CFB
    case CIPHER_DES:
      in_state.crypt_state.cipher = EVP_des_cfb();
      break;
#endif
#ifdef HAVE_EVP_DES_EDE3_CFB
    case CIPHER_3DES:
      in_state.crypt_state.cipher = EVP_des_ede3_cfb();
      break;
#endif
#ifdef HAVE_EVP_IDEA_CFB
    case CIPHER_IDEA:
      in_state.crypt_state.cipher = EVP_idea_cfb();
      break;
#endif
#ifdef HAVE_EVP_RC5_32_12_16_CFB
    case CIPHER_RC5_8:
      in_state.crypt_state.cipher = EVP_rc5_32_12_16_cfb();
      in_state.crypt_state.rounds = 8;
      break;
    case CIPHER_RC5_12:
      in_state.crypt_state.cipher = EVP_rc5_32_12_16_cfb();
      in_state.crypt_state.rounds = 12;
      break;
    case CIPHER_RC5_16:
      in_state.crypt_state.cipher = EVP_rc5_32_12_16_cfb();
      in_state.crypt_state.rounds = 16;
      break;
#endif
    default:
      send_error("can't set decryption cipher - invalid cipher: %d!",
                 cipher); /* invalid cipher */
      break;
  }
#else
  send_error("can't set decryption cipher - no OpenSSL support!");
#endif
}

void
cmd_set_crypt_in_key(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBCRYPTO
  if (in_state.crypt_state.key)
    send_error("can't set decryption key - already set!");

  in_state.crypt_state.keylen = cmd->datalen;
  in_state.crypt_state.key = malloc(cmd->datalen);

  memcpy(in_state.crypt_state.key, cmd->data, cmd->datalen);
#else
  send_error("can't set decryption key - no OpenSSL support!");
#endif
}

void
cmd_start_crypt_in(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBCRYPTO                                                           
  if (in_state.crypt)
    send_error("can't start decryption - already started!");

  if (!in_state.crypt_state.cipher)
    send_error("can't start decryption - no cipher set!");

  if (!in_state.crypt_state.key)
    send_error("can't start decryption - no key set!");

  in_state.crypt = 1;
  if (!EVP_DecryptInit(&in_state.crypt_state.ctx,
                       in_state.crypt_state.cipher, NULL, NULL))
    send_error("can't start decryption - DecryptInit (1) failed: %s!",
               ERR_error_string(ERR_get_error(), NULL));

  if (!EVP_CIPHER_CTX_set_key_length(&in_state.crypt_state.ctx,
                                     in_state.crypt_state.keylen))
    send_error("can't start decryption - set_key_length failed: %s!",
               ERR_error_string(ERR_get_error(), NULL));

  in_state.crypt_state.ivlen =
    EVP_CIPHER_CTX_iv_length(&in_state.crypt_state.ctx);

  if (in_state.crypt_state.ivlen)
    in_state.crypt_state.iv = calloc(in_state.crypt_state.ivlen, 1);

  if (in_state.crypt_state.rounds)
  {
    if (!EVP_CIPHER_CTX_ctrl(&in_state.crypt_state.ctx,
                             EVP_CTRL_SET_RC5_ROUNDS,
                             in_state.crypt_state.rounds,
                             NULL))
      send_error("can't start decryption - SET_RC5_ROUNDS failed: %s!",
                 ERR_error_string(ERR_get_error(), NULL));
  }

  if (!EVP_DecryptInit(&in_state.crypt_state.ctx,
                       NULL,
                       in_state.crypt_state.key,
                       in_state.crypt_state.iv))
    send_error("can't start decryption - DecryptInit (2) failed: %s!",
               ERR_error_string(ERR_get_error(), NULL));
#else
  send_error("can't start decryption - no OpenSSL support!");
#endif
}

void
cmd_set_crypt_out_cipher(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBCRYPTO
  unsigned int cipher = *cmd->data;

  if (out_state.crypt_state.cipher)
    send_error("can't set encryption cipher - already set!");

  switch (cipher)
  {
#ifdef HAVE_EVP_BF_CFB
    case CIPHER_BF:
      out_state.crypt_state.cipher = EVP_bf_cfb();
      break;
#endif
#ifdef HAVE_EVP_CAST5_CFB
    case CIPHER_CAST:
      out_state.crypt_state.cipher = EVP_cast5_cfb();
      break;
#endif
#ifdef HAVE_EVP_DES_CFB
    case CIPHER_DES:
      out_state.crypt_state.cipher = EVP_des_cfb();
      break;
#endif
#ifdef HAVE_EVP_DES_EDE3_CFB
    case CIPHER_3DES:
      out_state.crypt_state.cipher = EVP_des_ede3_cfb();
      break;
#endif
#ifdef HAVE_EVP_IDEA_CFB
    case CIPHER_IDEA:
      out_state.crypt_state.cipher = EVP_idea_cfb();
      break;
#endif
#ifdef HAVE_EVP_RC5_32_12_16_CFB
    case CIPHER_RC5_8:
      out_state.crypt_state.cipher = EVP_rc5_32_12_16_cfb();
      out_state.crypt_state.rounds = 8;
      break;
    case CIPHER_RC5_12:
      out_state.crypt_state.cipher = EVP_rc5_32_12_16_cfb();
      out_state.crypt_state.rounds = 12;
      break;
    case CIPHER_RC5_16:
      out_state.crypt_state.cipher = EVP_rc5_32_12_16_cfb();
      out_state.crypt_state.rounds = 16;
      break;
#endif
    default:
      send_error("can't set encryption cipher - invalid cipher %d!",
                 cipher); /* invalid cipher */
  }
#else
  send_error("can't set encryption cipher - no OpenSSL support!");
#endif
}

void
cmd_set_crypt_out_key(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBCRYPTO
  if (out_state.crypt_state.key)
    send_error("can't set encryption key - already set!");

  out_state.crypt_state.keylen = cmd->datalen;
  out_state.crypt_state.key = malloc(cmd->datalen);

  memcpy(out_state.crypt_state.key, cmd->data, cmd->datalen);
#else
  send_error("can't set encryption key - no OpenSSL support!");
#endif
}

void
cmd_start_crypt_out(struct ctrl_command *cmd)
{
#ifdef HAVE_LIBCRYPTO
  if (out_state.crypt)
    send_error("can't start encryption - already started!");
  
  if (!out_state.crypt_state.cipher)
    send_error("can't start encryption - no cipher set!");

  if (!out_state.crypt_state.key)
    send_error("can't start encryption - no key set!");

  out_state.crypt = 1;
  if (!EVP_EncryptInit(&out_state.crypt_state.ctx,
                       out_state.crypt_state.cipher, NULL, NULL))
    send_error("can't start encryption - EncryptInit (1) failed: %s!",
               ERR_error_string(ERR_get_error(), NULL));

  if (!EVP_CIPHER_CTX_set_key_length(&out_state.crypt_state.ctx,
                                     out_state.crypt_state.keylen))
    send_error("can't start encryption - set_key_length failed: %s!",
               ERR_error_string(ERR_get_error(), NULL));

  out_state.crypt_state.ivlen =
    EVP_CIPHER_CTX_iv_length(&out_state.crypt_state.ctx);   

  if (out_state.crypt_state.ivlen)
    out_state.crypt_state.iv = calloc(out_state.crypt_state.ivlen, 1);

  if (out_state.crypt_state.rounds)
  {
    if (!EVP_CIPHER_CTX_ctrl(&out_state.crypt_state.ctx,
                             EVP_CTRL_SET_RC5_ROUNDS,
                             out_state.crypt_state.rounds, NULL))
      send_error("can't start encryption - SET_RC5_ROUNDS failed: %s!",
                 ERR_error_string(ERR_get_error(), NULL));
  }

  if (!EVP_EncryptInit(&out_state.crypt_state.ctx,
                       NULL,
                       out_state.crypt_state.key,
                       out_state.crypt_state.iv))
    send_error("can't start encryption - EncryptInit (2) failed: %s!",
               ERR_error_string(ERR_get_error(), NULL));
#else
  send_error("can't start encryption - no OpenSSL suppport!");
#endif
}

void
cmd_init(struct ctrl_command *cmd)
{
  if (in_state.active || out_state.active)
    send_error("CMD_INIT sent twice!");

  in_state.active = 1;
  out_state.active = 1;
  CONTROL_R.read_cb = read_ctrl;
  CONTROL_W.write_cb = NULL;
  LOCAL_R.read_cb = read_data;
  LOCAL_W.write_cb = NULL;
  REMOTE_R.read_cb = read_net;
  REMOTE_W.write_cb = NULL;
}
