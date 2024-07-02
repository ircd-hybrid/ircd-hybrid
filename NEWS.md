#### Noteworthy changes in version 8.2.45 (2024-07-02)
* The module API has been rewritten for improved flexibility. A `modules.conf` file is now
  required for configuring and loading modules. For further information, refer to the
  `doc/reference.modules.conf`.
* The `INFO` subsystem has been updated to support dynamic registration and unregistration
  of info entries. This allows modules to register and unregister their own info entries,
  which are shown in the `INFO` output.
* Added support for a flattened `MAP` output when `serverhide::flatten_links` is enabled.
  This allows users to view a simplified network topology where all servers appear as if
  they are directly connected to the local server.


#### Noteworthy changes in version 8.2.44 (2024-06-15)
* Fixed FTCBFS issue caused by ./configure using macros that lacked special handling
  for cross-compilation scenarios
* Fixed the issue where `XLINE` and `UNXLINE` were not working properly on servers within
  a cluster
* Command-line options now support both short (`-c`) and long (`--configfile`) formats.
  The available options are:
  * `-c` or `--configfile` for the configuration file
  * `-k` or `--klinefile` for the kline database file
  * `-d` or `--dlinefile` for the dline database file
  * `-x` or `--xlinefile` for the xline database file
  * `-r` or `--resvfile` for the resv database file
  * `-l` or `--logfile` for the log file
  * `-p` or `--pidfile` for the PID file
  * `-f` or `--foreground` to run in the foreground
  * `-v` or `--version` to print the version and exit
  * `-h` or `--help` to display help information
* The new IRC operator flag, `message:mass`, has been implemented. This flag controls
  access to sending mass messages using the `NOTICE $$*.mask` command.
* Upon connecting, a user will now receive a notice with their client certificate
  fingerprint, if provided.
* The `INFO` command now includes the `serverinfo::name`, `serverinfo::sid`, and
  `serverinfo::description` configuration options in its output.
* The `STATS` subsystem has been rewritten to support dynamic registration and unregistration
  of stats handlers. This allows modules to register and unregister their own stats handlers.
* Implemented hostname cloaking API to improve user privacy and security by obfuscating real
  IP addresses. The cloaking process uses CIDR masking, SHA3 hashing, and base32 encoding to
  generate secure and unique cloaked hostnames. The following configuration directives
  have been introduced:
  * `general::cloak_enabled`: Enable or disable hostname cloaking.
  * `general::cloak_cidr_len_ipv4`: CIDR length for IPv4 addresses used in hostname cloaking.
  * `general::cloak_cidr_len_ipv6`: CIDR length for IPv6 addresses used in hostname cloaking.
  * `general::cloak_num_bits`: Number of bits for the MAC computation used in hostname cloaking.
  * `general::cloak_secret`: Secret key used in the MAC computation for hostname cloaking.
  * `general::cloak_suffix`: Suffix appended to the cloaked hostname.
* Added user mode `+x` (cloak) to activate hostname cloaking for the user, replacing their
  real IP address with a cloaked hostname.
* The `INFO` command now includes the new cloaking configuration options in its output. The
  following cloaking-related configuration directives will be shown:
  * `general::cloak_enabled`
  * `general::cloak_cidr_len_ipv4`
  * `general::cloak_cidr_len_ipv6`
  * `general::cloak_num_bits`
  * `general::cloak_secret` (displayed as `<REDACTED>` for security)
  * `general::cloak_suffix`


#### Noteworthy changes in version 8.2.43 (2022-09-26)
* Due to ongoing protocol modernizations and deprecation of old backwards compatibility
  code, ircd-hybrid is now no longer link compatible to 8.2.33 and below.
  As for the Anope IRC Services, 2.0.8 is the minimum supported version now.
* Implemented channel mode `V`. `INVITE` cannot be used on channels with that mode set.
* `WHOIS` on clients connected via TLS now also shows some details about the TLS version
  and cipher being used
* Removed user mode `d` (debugging notices)


#### Noteworthy changes in version 8.2.42 (2022-08-28)
* Added support for reproducible builds using the `SOURCE_DATE_EPOCH` environment
  variable. See https://reproducible-builds.org/docs/source-date-epoch/ for more
  information.
* Implemented channel mode `Q`. `KICK` cannot be used on channels with that mode set.
* Implemented user mode `Z`. Users with that mode set may only receive private
  messages from other users that are connected via TLS.
* Fixed issue where `WHO nick` on invisible clients (user mode `i`) wouldn't work


#### Noteworthy changes in version 8.2.41 (2022-07-15)
* Fixed issue where `WHO` didn't work on channel names with two or more consequent
  asterisk characters
* IRCv3 WHOX has been implemented. See `doc/who.txt` for more information about
  the new `WHO` options and features.
* Clients that are connected via TLS are now flagged with the letter `S` in the
  who reply


#### Noteworthy changes in version 8.2.40 (2022-07-02)
* `channel::disable_fake_channels` now also blocks strikethrough text (0x1E (30))
* `KNOCK` can now be used on private channels. Channel mode `K` may be used instead
  to control whether or not `KNOCK` is allowed on a channel.
* Support for `/dev/poll` has been dropped
* `INFO` now also reports configured values of `channel::default_join_flood_count`
  and `channel::default_join_flood_time`
* The founder `q` and admin `a` channel prefix modes have been implemented.
  These are optional and can be enabled with the new `channel::enable_owner`
  and `channel::enable_admin` configuration directives.
* Channel half-ops may now kick other half-ops
* Extban `$K` of type acting has been implemented. This extban prevents
  matching users from using the `KNOCK` command.
* Server-side channel mode locking `MLOCK` has been implemented
* Fixed server name leak in `WHOWAS` with `serverhide::hide_services` enabled


#### Noteworthy changes in version 8.2.39 (2021-08-14)
* `hidechans` and `hideidle` may now be set in `general::oper_only_umodes`
* OpenSSL 3.0 compatibility improvements
* Fixed crashing issue in the mkpasswd tool with older glibc
* Fixed issue where the ircd wouldn't listen on both IPv4 and IPv6 ports in
  case only a port but no address has been specified in a listen {} block
* Fixed a `STATS P` displaying issue with compressed ipv6 loopback/inaddr_any


#### Noteworthy changes in version 8.2.38 (2021-01-17)
* Backwards compatibility mode for ircd-hybrid 8.2.22 and below has been removed
* Minimum supported version of the Anope IRC services is now 2.0.8
* Fixed displaying issue with channel `MODE` messages
* Characters valid for user names (ident) for local clients are now `[A-Za-z0-9._-]`.
  Special characters like ``}|{`^]\[$``, that were allowed previously, are no longer
  valid. Also user names may not begin with `.`, `_`, or `-`.
* The `general::dots_in_ident` configuration directive has been renamed to
  `general::specials_in_ident` and now covers the `-` and `_` characters in
  addition to `.`
* Fixed issue with clients connected from IPv6 localhost that, depending on the
  system's `getaddrinfo` implementation, could lead to a crash of remote servers


#### Noteworthy changes in version 8.2.37 (2020-12-26)
* Implemented IRCv3 `CAP 302`
* Implemented IRCv3 `cap-notify` capability
* In case a client sends multiple `PASS` messages, ircd only accepts the password
  sent in the first `PASS` message instead of the last one
* Missing help file for `MONITOR` has been added
* Fixed slightly off memory count for motds in `STATS z`


#### Noteworthy changes in version 8.2.36 (2020-12-04)
* The old `WATCH` implementation has been replaced with IRCv3.2 `MONITOR`. For this,
  the `general::max_watch` configuration directive has been renamed to
  `general::max_monitor`.
* User mode `B` has been implemented. Clients with that mode set are marked as a
  bot in both `WHOIS` and `WHO`. This mode can only be set by IRC operators (as
  long as the `bot` directive is set in `general::oper_only_umodes`), servers,
  and services.
  This mode can for example be used to mark HOPM as official network bot.


#### Noteworthy changes in version 8.2.35 (2020-11-14)
* Fixed issue where servers could propagate truncated ban masks during net-join


#### Noteworthy changes in version 8.2.34 (2020-11-01)
* Re-implement backwards compatibility mode for old ircd-hybrid 8.2.23 and below.
  Final removal is scheduled for early 2021.
* For consistency, the `general::network_desc` configuration directive has been
  renamed to `general::network_description`
* Server notices that previously have been sent to user modes `f` and `u` are now
  sent to user mode `j` (reject notices) instead. Due to this change, `unauth` and
  `full` have been removed from `general::oper_only_umodes`, `general::oper_umodes`,
  and `operator::umodes`.
* User mode `b` (bots) has been replaced with `f` (flood). Spam/flood notices are now
  sent to this user mode. For this, `bots` has been removed from
  `general::oper_only_umodes`, `general::oper_umodes`, and `operator::umodes`.
  `flood` has been added instead to these configuration directives.
* Stricten server/user ID validation. IDs have to be all uppercase everywhere now.


#### Noteworthy changes in version 8.2.33 (2020-09-07)
* Added `client` option to `listener::flags`
* Added `defer` option to `listener::flags`
* IRC operators may now use CIDR notation in `WHO`


#### Noteworthy changes in version 8.2.32 (2020-08-16)
* `RESV` couldn't be issued in case no reason has been supplied. This has been fixed.
* Fixed possible `RPL_WHOISCHANNELS` line truncation of remote replies
* Extban `$t` of type matching has been implemented. This extban allows matching
  based on TLS protocol version and/or cipher suite.
* Implemented channel mode `K`. `KNOCK` cannot be used on channels with that mode set.
* `STATS ?` is now oper-only


#### Noteworthy changes in version 8.2.31 (2020-05-03)
* macOS compatibility fixes
* Removed `spoof_notice` from `auth::flags`. With vhosts now this notice doesn't make
  much sense anymore.
* Fixed issue where ban masks might become malformed if set by remote clients/servers
* Fixed issue with channel mode `c` where high ascii characters can be erroneously
  detected as control characters


#### Noteworthy changes in version 8.2.30 (2020-03-01)
* `QUOTE HELP extban` didn't work because the extban help file hasn't been
  installed properly during `make install`
* Fixed broken libcrypto detection which caused the ircd not to work with
  OpenSSL under certain circumstances
* Extban `$n` of type acting has been implemented. This extban prevents
  matching users from changing their nick while in the channel. Users
  with voice or above are not affected.
* Channel mode `N` has been changed so channel members with `v` (voice) can
  change their nick name as well


#### Noteworthy changes in version 8.2.29 (2020-02-19)
* Extbans have been implemented. Currently supported extbans:

  Matching:

  * `$a:<account>`   Matches users logged into a matching account.
  * `$c:<channel>`   Matches users that are on the given channel. An additional
                     prefix of either `@`, `%`, or `+` can be specified to test
                     for certain channel privileges.
  * `$o:<class>`     Matches IRC operators that have joined a class
                     matching the mask.
  * `$r:<realname>`  Matches users with a matching realname.
  * `$s:<server>`    Matches users that are connected to a server matching the mask.
  * `$u:<modes>`     Matches users having the specified user modes set or not set.
  * `$z:<certfp>`    Matches users having the given TLS certificate fingerprint.

  Acting:

  * `$j:<banmask>`   Prevents matching users from joining the channel.
  * `$m:<banmask>`   Blocks messages from matching users. Users with voice
                     or above are not affected.

  For more details, see `help/extban`.
* Added `channel::enable_extbans` configuration option. See `doc/reference.conf`
  for more information.


#### Noteworthy changes in version 8.2.28 (2020-01-26)
* Fixed issue with topics set by `TBURST` not being propagated properly to clients
* Allow IRC operators to search for real hosts in `WHO`
* Ban/exempt/invex masks are now also tested against realhosts to prevent clients
  from bypassing channel bans by activating a fakehost


#### Noteworthy changes in version 8.2.27 (2020-01-22)
* Experimental support for wolfSSL has been implemented. Minimum supported version is 4.3.0
* The `--enable-openssl`, `--enable-gnutls` switches, and their disabling counterparts
  `--disable-openssl` and `--disable-gnutls`, have been replaced with the `--with-tls`
  switch which takes one of the following options: `openssl`, `wolfssl`, `gnutls`,
  and `none`.
  If nothing has been specified, configure tries to autodetect in the following order:
  OpenSSL/LibreSSL -> GnuTLS -> wolfSSL.
* Fixed segfault with GnuTLS/libgmp in case there's no DH parameters file
  defined in `serverinfo::ssl_dh_param_file` or if that file is missing
* The connection timeout for connect {} blocks can now be configured via
  the `connect::timeout` configuration directive
* Minimum supported OpenSSL version is 1.1.1 now
* Minimum supported GnuTLS version is 3.6.5 now
* Supported TLSv1.3 cipher suites can now be configured explicitely via the
  new `serverinfo::tls_cipher_suites` configuration directive
* In the serverinfo {} block, the following configuration directives have been renamed:
    `ssl_certificate_file` -> `tls_certificate_file`
    `ssl_dh_param_file` -> `tls_dh_param_file`
    `ssl_dh_elliptic_curve` -> `tls_supported_groups`
    `ssl_cipher_list` -> `tls_cipher_list`
    `ssl_message_digest_algorithm` -> `tls_message_digest_algorithm`
* In the operator {} block, the following configuration directives have been renamed:
    `ssl_certificate_fingerprint` -> `tls_certificate_fingerprint`
    `ssl_connection_required` -> `tls_connection_required`
* In the connect {} block, the following configuration directives have been renamed:
    `ssl_cipher_list` -> `tls_cipher_list`
    `ssl_certificate_fingerprint` -> `tls_certificate_fingerprint`


#### Noteworthy changes in version 8.2.26 (2019-05-31)
* The `general::tkline_expire_notices` configuration directive has been
  replaced with user mode `X`. *LINE expiration notices are sent to IRC
  operators with that mode set
* Fixed issue with `/rehash conf` creating duplicated class entries
  instead of updating existing ones that are already in use


#### Noteworthy changes in version 8.2.25 (2019-04-24)
* The `class::number_per_ip`, `class::max_local` and `class::max_global`
  configuration directives have been replaced with just `class::number_per_ip_local`
  and `class::number_per_ip_global`. The `class::max_local` basically was
  redundant as it had the same functionality as `class::number_per_ip`.
* Adding RESVs with wildcards no longer requires administrator privileges
* The `general::ignore_bogus_ts` configuration option has been deprecated
* TLSv1.1 and TLSv1.0 are no longer supported and have been disabled in
  the OpenSSL and GnuTLS module
* Minimum supported OpenSSL version is 1.0.1f now
* Minimum supported GnuTLS version is 3.5.8 now
* The `serverinfo::vhost` and `serverinfo:vhost6` configuration directives have
  been deprecated. If you need to bind a specific address you can specify one
  in the connect {} block.
* The `connect::vhost` configuration directive has been renamed to `connect::bind`


#### Noteworthy changes in version 8.2.24 (2018-04-05)
* Added `STATS s` to show configured pseudo {} blocks
* Implemented channel mode `N` which prevents users from changing their
  nick while in a channel with that mode set
* Services clients are now shown with `is a Network Service` in `WHOIS`


#### Noteworthy changes in version 8.2.23 (2018-03-26)
* IRC operators are now able to see a user's resolved hostname in `WHOWAS`,
  and `WHOIS` even if the user has a fakehost/vhost
* `RPL_WELCOME` now does use the rfc2812 style nick!user@host format
* Removed rudimentary libgeoip support
* Added `--enable-efence` switch to allow easy linking with the
  electric fence memory debugger library
* `JOIN 0` is no longer supported
* Fixed bug where ircd would not remove `RPL_WHOISOPERATOR` based svstags
  when deoppering
* Fixed `unknown closes` statistic in `STATS t` showing invalid values sometimes


#### Noteworthy changes in version 8.2.22 (2017-03-26)
* Implemented channel mode `L`. Channels with that mode set can make use of an
  extended ban list size specified with the new `channel::max_bans_large`
  configuraton option. This mode can be set only by IRC operators or servers.
* Implemented channel mode `u` which hides bmask (+b/+e/+I) lists and mode changes
  to non-chanops everywhere
* Fixed an issue with `TRACE` where remote servers would reply with `RPL_TRACEUSER`
  numerics containing UIDs
* `STATS z` now shows simple memory stats of servers linked to the network
* Added support for remote `ETRACE`


#### Noteworthy changes in version 8.2.21 (2016-11-27)
* The `general::default_floodtime` configuration option has been added
  along with the `SET FLOODTIME` command. These allow to fine-tune the
  message throttling better.
* Fixed an issue with `INVITE` not showing the list of channels the
  sender is invited to


#### Noteworthy changes in version 8.2.20 (2016-11-05)
* `INFO` now shows GnuTLS/OpenSSL library/header versions
* Added `channel::max_invites` configuration option. See `doc/reference.conf`
  for more information.
* `INVITE` expirations have been implemented. Expire time can be adjusted with
  the `channel::invite_expire_time` configuration directive.
* `WHOIS` notices to IRC operators have been re-added. User mode `y` (spy) is
  required to see them.
* The maximum line length for motd files has been increased to 320 bytes to
  support multibyte encodings better


#### Noteworthy changes in version 8.2.19 (2016-08-21)
* Fixed a possible server name leak in `WHO` with server hiding enabled
* `WHO` now allows IRC operators to search by IP address
* Admins no longer can see IP addresses in `STATS P` with
  `serverhide::hide_server_ips` enabled
* User mode `n` now shows nick name changes from remote clients, too


#### Noteworthy changes in version 8.2.18 (2016-06-22)
* Fixed an assert when a client sends invalid `LIST` options
* Fixed invalid memory stats of channel invites in `STATS z`


#### Noteworthy changes in version 8.2.17 (2016-04-21)
* Fixed core on `REHASH CONF` with `general::whowas_history_length`
  set to 0
* Fixed possible core on `INVITE` with `channel::max_channels` set to 0


#### Noteworthy changes in version 8.2.16 (2016-03-20)
* Added `general::whowas_history_length` configuration option which
  allows to define the maximum length of the `WHOWAS` nickname history
* Services are now allowed to override `general::min_nonwildcard`,
  and `general::min_nonwildcard_simple` settings
* Minor updates to help files


#### Noteworthy changes in version 8.2.15 (2016-02-24)
* Added proper support for Raspbian/ARM. Gracias to Beave/2600.net
  for providing a box for testing purposes.
* Fixed an assert with empty `user = ""` directives in auth {} blocks
* `STATS z` now shows allocated listeners
* Fixed bug where `can_flood` auth {} flags did not work on channels


#### Noteworthy changes in version 8.2.14 (2016-02-09)
* Fixed server clustering
* Major cleanups to the configuration subsystem
* Improvements to libGeoIP support:
  - Works now with IPv6 addresses
  - Added `libgeoip_database_options`, `libgeoip_ipv4_database_file`,
    and `libgeoip_ipv6_database_file` configuration directives to the
    serverinfo {} block
* Further improvements to GnuTLS support


#### Noteworthy changes in version 8.2.13 (2016-02-02)
* Implemented support for GnuTLS. Currently ./configure's autodetection
  intentionally prefers OpenSSL over GnuTLS, so OpenSSL detection needs
  to be disabled explicitely by using the `--disable-openssl` switch.
* Minimum supported GnuTLS version is 3.3.8 now
* Minimum supported OpenSSL version is 1.0.1d now
* Added support for remote `REHASH`: `REHASH <server> <option>`
* Added `rehash:remote` IRC operator privilege flag
* Added `rehash` type to shared {} blocks
* Fixed minor memory leak with shared {} and cluster {} blocks


#### Noteworthy changes in version 8.2.12 (2016-01-05)
* Character case mapping is `ascii` now. It is recommended to update all
  servers on the network to prevent possible channel desynchronizations
  and nick name collision kills
* Added channel mode `T` which forbids `NOTICE` to be sent to a channel
* Fixed minor `SVSTAG` memory leak
* Fixed broken `PART` message blocking mechanism
* ircd now makes use of up to 8 name servers that are specified in
  `/etc/resolv.conf`
* The `-klinefile`, `-dlinefile`, etc. switches didn't work at all
* Fixed possible core on ident lookups if ircd is out of file descriptors
* Far client exit notices (user mode `F`) now show IP addresses, too
* Made idle time look nicer in `STATS v|p` by using a formatted time string
* `general::ts_warn_delta`, and `general::ts_max_delta` can be set to 0 now


#### Noteworthy changes in version 8.2.11 (2015-11-19)
* Implemented IRCv3.2 `invite-notify` extension
* Implemented IRCv3.2 `chghost` extension
* Added `channel::invite_delay_channel` configuration option


#### Noteworthy changes in version 8.2.10 (2015-11-06)
* The `serverhide::links_delay` configuration directive has been renamed
  to `serverhide::flatten_links_delay`
* Added `serverhide::flatten_links_file` configuration option
* Fixed bug where changing `serverhide::flatten_links_delay` on runtime
  would not have any effect
* mkpasswd (tools): fixed broken bcrypt support on *BSD in conjunction with
  the `-s` and `-l` switches. Dropped MD5, DES and Extended DES support.
* Removed `CHALLENGE` in favor of ssl certificate fingerprint enabled
  operator {} blocks
* RSA keys with less than 2048 bits are no longer supported; same applies
  to the DH param file
* Added missing IRC operator privilege flags to `STATS o`. For a full list
  of flags see `doc/reference.conf`


#### Noteworthy changes in version 8.2.9 (2015-09-13)
* Database files and `links.txt` are now stored in `/var/lib` instead
  of `/etc`, so make sure to move your k/d/x-line database files to
  the new path before (re)starting the ircd
* The splitmode logic has been removed along with the following
  channel {} block configuration directives:
  `default_split_user_count`, `default_split_server_count`,
  `no_create_on_split`, `no_join_on_split`
* Added `xline_exempt` to auth {} block flags
* `serverinfo::sid` is now optional. A unique SID is now automatically
  generated based on the server's name and description
* Various fixes to the mkpasswd tool
* If supported by the compiler, ircd-hybrid now compiles with
  `-fstack-protector-strong` instead of `-fstack-protector`
* Services can now add RESVs (SQLINEs) that have wildcards in it
* Channel name RESVs are now sanity checked for too broad masks
* `class::connectfreq` now works properly with values lower than 300 seconds
* Implemented IRCv3.1 `account-notify` extension
* The `general::oper_pass_resv` configuration directive has been deprecated
  in favor of the new `join:resv`, and `nick:resv` IRC operator flags.
  See `doc/reference.conf` for more information.
* Added `resv`, and `unresv` IRC operator flags. Previously, all
  IRC operators were allowed to `RESV` and `UNRESV`, regardless of configured
  privileges.
* Added `close` to IRC operator flags
* ircd is using ISO 8601 date and time notation in most places now


#### Noteworthy changes in version 8.2.8 (2015-05-10)
* ircd now rejects remote k-line requests for user@host mask that don't
  have at least `general::min_nonwildcard` non-wildcard characters in it
* Configuration related server notices are now sent to admins only as
  they potentially could leak passwords and other sensitive data to IRC
  operators that don't have administrator privileges
* The `GLINE`/`GUNGLINE` commands have been removed. `KLINE` in conjunction
  with cluster {} and/or shared {} blocks is now the recommended
  way to add global user@host mask based server bans
* Added `dline_min_cidr`, `dline_min_cidr6`, `kline_min_cidr`, and
 `kline_min_cidr6` configuration options to the general {} block
* Fixed bug where a `REHASH` would clear all X-Lines and RESVs that have
  been set with the `XLINE`/`RESV commands`
* Fixed broken temporary remote XLINEs
* The `general::havent_read_conf` configuration directive has been removed


#### Noteworthy changes in version 8.2.7 (2015-04-05)
* Fixed a potential buffer overflow with the `BMASK` inter-server command
* Fixed undefined behavior in the `HELP` command module which could
  lead to stack corruption
* Removed useless help files for inter-server commands


#### Noteworthy changes in version 8.2.6 (2015-03-29)
* `INFO` now shows configured values of `max_watch` and `stats_m_oper_only`
* `WHOWAS` now shows IP addresses to IRC operators
* Fixed bug that would allow remote clients to bypass the hard
  limit of max `WHOWAS` entries to be returned


#### Noteworthy changes in version 8.2.5 (2015-02-24)
* Fixed core on Mac OSX 10.10 and possibly some other systems when parsing
  the `ircd.conf` with configured pseudo {} blocks


#### Noteworthy changes in version 8.2.4 (2015-02-17)
* Added `SVSTAG` command which services may use to add tags to users which can
  be seen in `WHOIS`
* Added `oper::whois` configuration option which allows to override the default
  `RPL_WHOISOPERATOR` numeric string shown in `WHOIS`
* IRC operators may now use +O on a channel even if they are only a half-op
* Fixed bug where `TOPIC` messages were not n!u@h prefixed in case of `TBURST`
  issued by services clients


#### Noteworthy changes in version 8.2.3 (2015-02-11)
* The following configuration directives have been renamed:
   `max_clients` -> `default_max_clients`
   `join_flood_count` -> `default_join_flood_count`
   `join_flood_time` -> `default_join_flood_time`
* Fixed bug where `REHASH` would always reset the `MAX`, `JFLOODTIME`, and
  `JFLOODCOUNT` values that have been changed from within IRC via the `SET`
  command
* Added channel mode `C` which prevents users from sending CTCPs to a channel
* Fixes to the `NOTICE`/`PRIVMSG` anti-flood logic
* Allow to disable the `NOTICE`/`PRIVMSG` anti-flood mechanism by setting the
  `general::default_floodcount` configuration option to 0
* Updated some help files
* IRC operators may now see certificate fingerprints, user modes and hidden
  channels via `WHOIS` as well. This used to be admin only.


#### Noteworthy changes in version 8.2.2 (2015-01-20)
* Implemented IRCv3.1 `extended-join` extension
* Channel half-ops can now use `INVITE` as well
* Fixed broken `make install -jX`
* `m_opme.c` has been added to `modules/extra`. Can be used on opless channels only.
* Added `opme` to IRC operator flags
* Updated several help files
* The `general::hide_spoof_ips` configuration option has been deprecated
* The `general::true_no_oper_flood` configuration option has been deprecated.
  IRC operators still can have higher `flood` limits with `no_oper_flood = yes;`
  hoewever, they are no longer allowed to bypass RecvQ limits.
* Added `general::stats_m_oper_only` configuration option
* Remote client connection notices (user mode `F`) now do show IP addresses, too


#### Noteworthy changes in version 8.2.1 (2014-10-21)
* Fixed bug where `UNDLINE remote.server IP` did not work as expected
* Servers are now allowed to add/remove K-/D-/X-lines and RESVs
* User mode `G` now no longer allows to override user mode `g`
* Due to potential weakness, TLS session caching and session tickets
  have been disabled
* Minor improvements to TS6 implementation
* `WHOWAS` now shows the name of the services account a user was logged in


#### Noteworthy changes in version 8.2.0 (2014-08-24)
* Successful IRC operator logins are now announced globally via `GLOBOPS`
* Cleanups and improvements to the resolver code
* Cleanups and improvements to the `poll` I/O event notification support
* A topic mask can now be specified within the `LIST` options
* All users may now see channel modes in the `LIST` reply
* Fixed bug where `NOTICE +#somechan` did allow bypassing resv {} channels,
  or channels that are set +c (no control codes)
* pseudo {} blocks also known as service aliases have been implemented.
  See `doc/reference.conf` for more information.
* Removed `general::services_name` configuration option. This is now no
  longer needed.


#### Noteworthy changes in version 8.2.0rc2 (2014-08-03)
* Improved `AWAY` throttling to allow for better fine-tuning. See the
  newly added `away_count` and `away_time` configuration directives
  in the general {} block.
* Support for the `select` I/O event notification has been dropped


#### Noteworthy changes in version 8.2.0rc1 (2014-07-20)
* Miscellaneous code cleanups and stabilization fixes
* `./configure` now requires OpenSSL 0.9.8o or above in order
  to enable TLS/SSL support


#### Noteworthy changes in version 8.2.0beta4 (2014-07-06)
* Channel halfops are now an integral part of ircd-hybrid and can't be disabled anymore
* Added flood control for the `INVITE` command. See channel {} block in `reference.conf`.
* Changed flood control logic for the `KNOCK` command. See channel {} block in `reference.conf`.
* `INVITE` without any parameters now shows a list of channels a client is invited to
* The `OPERWALL` command has been removed. Use `GLOBOPS` instead.
* Added `max_channels` to class {} blocks
* Added `throttle_count` configuration option to the general {} block
* Added `ssl_message_digest_algorithm` configuration option to serverinfo {} block.
  See `doc/reference.conf` for more information.
* Added support for Elliptic Curve Diffie-Hellman (ECDH). Also an elliptic curve can be
  specified via the `serverinfo::ssl_dh_elliptic_curve` configuration option.
* Removed `ssl_server_method` and `ssl_client_method` configuration options.
  ircd now only allows TLSv1, TLSv1.1 and TLSv1.2 protocols depending
  on the OpenSSL version. SSLv3 is no longer supported.


#### Noteworthy changes in version 8.2.0beta3 (2014-05-26)
* Code cleanups/performance improvements


#### Noteworthy changes in version 8.2.0beta2 (2014-05-15)
* Renamed `general::warn_no_nline` configuration directive to `general::warn_no_connect_block`
* Fixed bug with `WHOIS` not showing a list of channel names as expected
* Added user mode `q` which hides idle and signon time in `WHOIS`
* Added user mode `p` which hides channel list in `WHOIS`


#### Noteworthy changes in version 8.2.0beta1 (2014-04-29)
* TS6 is now mandatory. ircd is no longer backwards compatible with TS5
  and below.
* `SVSJOIN` and `SVSPART` commands have been added
* Major code cleanups and refactoring. Improved overall performance
* `INFO` now also reports `MPATH` (path to main motd (Message of the Day) file)
  and `SPATH` (Path to server executable)
* Updated several help files


#### Noteworthy changes in version 8.1.20 (2014-07-20)
* Fixed `XLINE` not working as expected
* Fixed build with LibreSSL which hasn't compression support
* Miscellaneous stabilization and cosmetical fixes
* EGD support has been dropped


#### Noteworthy changes in version 8.1.19 (2014-07-05)
* Fixed `EOB` logic for remote servers
* Fixed bug where IRC operators that have the +g/+G/+R umodes set won't receive
  server notices for remote CONNECT/KLINE/DLINE/XLINE/RESV attempts
* Sending messages to user@server to local targets is now no longer possible,
  as this was an easy way to bypass +R/+G/+g user modes.
* Fixed splicode logic so `SPLITNUM` now works as expected
* Fixed `UNDLINE` not to require the IP address to be prepended with *@


#### Noteworthy changes in version 8.1.18 (2014-06-09)
* Fixed `CAP` issue for certain clients
* Fixed bug where `STATS p` would show an invalid amount of IRC operators
  in case there are any +H opers
* IRC operators may now no longer set a channel +O if they are only halfops (%)
* Channel halfops (%) may now no longer (de)halfop other channel members
* Channel halfops (%) may now no longer `KICK` other channel halfops
* Fixed compile warnings; code cleanups
* Fixed bug where the configuration parser wouldn't truncate the network name
  if `general::network_name` contains spaces


#### Noteworthy changes in version 8.1.17 (2014-05-01)
* Fixed possible `WATCH` core
* Fixed bug where the configuration parser wouldn't take time units
  into consideration for the `join_flood_time` and `throttle_time`
  configuration options
* Minor `LIST` optimization


#### Noteworthy changes in version 8.1.16 (2014-04-20)
* Fixed undefined behaviour with `crypt` returning `NULL`
  since glibc2.17 in certain cases
* Admins may now see all channel members via `WHO #channel`
  regardless of channel mode `s`
* Fixed corrupted `STATS U` output


#### Noteworthy changes in version 8.1.15 (2014-03-29)
* ircd binary is now again placed into `bin/` instead of `sbin/`
* mkpasswd in tools/ now defaults to MD5 instead of DES
* The `USERS` command has been removed
* Fixed issue with `SVSNICK` where clients self-collided when changing
  just the case of the nick name, i.e. somenick -> SomeNicK


#### Noteworthy changes in version 8.1.14 (2014-02-25)
* WHOWAS now honors `serverhide::disable_remote_commands`
* Improved TS6 inter-server communication
* Added `unxline` IRC operator flag
* Implemented IRCv3.2 `userhost-in-names` extension
* ircd now allows private RSA keys larger than 2048 bits
* Fixed bug where signals stopped from working after restarting
  the ircd via SIGINT
* Fixed bug where certain irc clients could not reconnect via TLS/SSL
* Fixed long-standing bug where +p channels have been shown
  in the `WHOIS` reply


#### Noteworthy changes in version 8.1.13 (2014-01-07)
* Fixed `EOB` not working for remote servers (resulted in fake direction notices)
* Fixed remote client connection notices for servers that are
  more than one hop away
* Fixed bug where the ircd didn't timeout SSL connections that
  haven't finished the SSL handshake
* Fixed several bugs with server hiding
* Updated/fixed help files
* `WHOIS` no longer sends a notice to IRC operators with user mode `y` (spy)


#### Noteworthy changes in version 8.1.12 (2013-12-22)
* `RPL_WHOISMODES` now uses the 379 numeric
* Serial number is now shown on start up
* Fixed possible channel mode desynch with services
* Fixed TS6 support with `LOCOPS`
* Minor code cleanups
* Fixed file descriptor leak with empty help files
* Fixed issue with `WEBIRC` where hostnames were not validated


#### Noteworthy changes in version 8.1.11 (2013-12-06)
* Administrators may now see channel modes in `LIST`
* Fixed compile error on BSD systems when building with `kqueue`


#### Noteworthy changes in version 8.1.10 (2013-11-25)
* Fixed bug with `kqueue` where it occasionally dropped updates
* Changed `WHOIS` to show certificate fingerprint to administrators only
* The `WHO` reply now shows if a nickname has been registered
  with NickServ. (`r` status flag)
* Fixed some flaws with server hiding
* Fixed bug where `STATS P` would leak ip addresses to remotely connected
  administrators, even if `serverhide::hide_server_ips` was set to `yes`
* Added `SVSKILL` command


#### Noteworthy changes in version 8.1.9 (2013-11-08)
* Added user mode `W`. Users connected via a webirc gateway get this
  mode set by servers.
* `WHOIS` now shows if a client is connected via a webirc gateway
* Administrators may now see +s channels a user is in with `WHOIS`.
  Secret channels are prepended with a tilde in the `WHOIS` reply.
* Administrators are now able to see all the user modes a user has
  set via `WHOIS`


#### Noteworthy changes in version 8.1.8 (2013-10-25)
* Fixed bug that could lead to a desynchronized nick database
  throughout the entire network if using services enforced
  nick names (`SVSNICK`)
* Cleaned up/modernized build system
* Add `-fstack-protector` to `CFLAGS` if available. Basically checks for
  buffer overflows/stack-smashing attacks.
* When using anope 1.9/2.0 services, `WHOIS` now shows the account name
  of a registered/identified client (numeric 330)
* Administrators can now see +s channels in the `LIST` reply


#### Noteworthy changes in version 8.1.7 (2013-08-18)
* Fixed issue with channel mode `n` having no functionality at all
* Fixed SSL certificate fingerprint validation for outgoing server connects
* Updated several documentation files


#### Noteworthy changes in version 8.1.6 (2013-08-02)
* Fixed possible core with empty motd files


#### Noteworthy changes in version 8.1.5 (2013-07-16)
* Fixed bug that would prevent servers from linking together
  if `connect::aftype` isn't set


#### Noteworthy changes in version 8.1.4 (2013-07-05)
* Added `xline` and `resv` logging types. See `doc/reference.conf`
  for more information
* Fixed bug where remote `STATS` requests were not rate limited
* Fixed core with empty `auth::spoof` entries
* Increased oper/auth/connect password length limit from 20 to 128
* Minor fixes to nickflood control code


#### Noteworthy changes in version 8.1.3 (2013-06-23)
* Fixed possible core on `STATS z`
* Revised `doc/reference.conf`
* Fixed broken `--disable-libgeoip` switch


#### Noteworthy changes in version 8.1.2 (2013-06-20)
* Added `general::cycle_on_host_change` configuration option
* Added `general::stats_u_oper_only` configuration option
* Added support for SHA-256 ssl certificate fingerprint based operator {}
  and connect {} blocks.
  In conjunction with Anope 1.9/2.0 IRC-services, clients are now also able
  to automatically identify for their nick with ssl certificate
  fingerprints.
* Added `operator::ssl_connection_required` configuration option. See
  `doc/reference.conf` for more information.
* Added user mode `S` (client is connected via SSL/TLS). Allows services
  to keep track of what users are connected via SSL, and allows to see
  ssl-status of remote clients in a `WHOIS`.
* Fixed a server name leak with server hiding enabled


#### Noteworthy changes in version 8.1.1 (2013-06-06)
* Moved `disable_remote_command` configuration directive from general {} block
  to serverhide {} block
* Minor code cleanups/performance improvements
* Fixed bug where IRC operators could see `LOCOPS` messages even if they don't
  have the `l` user mode set
* Fixed bug where non-SSL clients could join +S channels on non-SSL servers
* Implemented motd {} configuration blocks. See `doc/reference.conf` for more
  information
* `STATS T` shows configured MOTD files


#### Noteworthy changes in version 8.1.0 (2013-05-23)
* Minor code cleanups/performance improvements


#### Noteworthy changes in version 8.1.0rc1 (2013-05-19)
* Fixed broken spoofs


#### Noteworthy changes in version 8.1.0beta5 (2013-05-15)
* Removed `remote`, and `global_kill` oper flags, and added `connect`,
 `squit`, and `kill` flags for better fine-tuning instead. Whether or
  not a specific action is allowed on a remote server can be controlled
  by appending the `:remote` flag. For example: `kill` allows only local
  clients to be killed, whereas `kill:remote` allows to issue a `KILL` for
  remote clients
* Added `locops` and `wallops` to IRC operator flags
* Improve/cleanup `HELP` system


#### Noteworthy changes in version 8.1.0beta4 (2013-05-09)
* Implemented channel mode `M`. Clients that haven't identified their
  name with NickServ may not speak in a channel that has this mode set.
* Fixed weird idletimes shown in `TRACE`
* Added `nononreg` (user mode `R`) to `general::oper_umodes`
* Added user mode `F` (can see remote client connect/exit notices)


#### Noteworthy changes in version 8.1.0beta3 (2013-05-05)
* PCRE support has been dropped
* `STATS o` now shows how many times an operator {} block has been used.
  Similar to `STATS x|q`.
* Implemented channel mode `c`. Known from other ircds, this mode basically
  prevents users from sending messages including control codes to a channel
  that has this mode set.
* Fixed bug where bans were not checked against non-channel members when
  sending messages to a channel
* Removed `channel::quiet_on_ban` configuration option. This feature is
  now enabled by default.


#### Noteworthy changes in version 8.1.0beta2 (2013-04-28)
* Fixed broken compile with libGeoIP disabled
* Removed oper flag `nick_changes`. IRC operators can now set +n at will.
* Fixed shared {} blocks not working as expected
* Fixed spoofs not working as expected


#### Noteworthy changes in version 8.1.0beta1 (2013-04-25)
* Name/channel entries can't be stacked any longer within a single resv {}
  block. Each entry now requires its own resv {} block.
  Read `doc/reference.conf` for more details.
* Added `resv::exempt` configuration option. Exempt can be either a
  ISO 3166 alpha-2 two letter country code, or a nick!user@host mask.
  CIDR is supported.
* Removed `channel::restrict_channels` configuration option
* Preliminary libGeoIP support. Currently only used for exempt entries
  in resv {} blocks.
* Improved WEBIRC authentication; added `webirc` to `auth::flags`.
  A `webirc.` spoof is now no longer required.
* Implemented new memory pool allocator which basically is based upon Tor's
  mempool allocator for Tor cells
* Implemented new binary database storage for X-, D-, K-, G-Lines and RESVs.
  Temporary bans are now stored as well and will persist after a reboot.
* Channel based resv {} blocks may now contain wildcards
* NICK/JOIN now shows the actual reason of reserved nick-/channelnames
* contrib/ and its content has been enirely removed from the tree
* Added `serverhide::hide_services` configuration option
* Added `nononreg` (user mode `R`) to `oper::umodes` and `general::oper_only_modes`
* Implemented IRCv3.1 `away-notify` extension


#### Noteworthy changes in version 8.0.9 (2013-05-16)
* Fixed bug where ircd would sometimes drop a services link because
  of a missing argument to the `SVSMODE` command
* Fixed weird idletimes shown in `TRACE`


#### Noteworthy changes in version 8.0.8 (2013-04-28)
* `STATS s` now shows configured services {} blocks as well
* Fixed compile warnings, minor code cleanups and optimizations
* Increased nickname history length to 32768
* Unidentified/unregistered nicks may not speak in +R channels


#### Noteworthy changes in version 8.0.7 (2013-04-12)
* Services may now set a channel topic without joining the channel first
* Fixed bug where `WHOIS` would send empty sockhost information on TS5 servers
* Remote server connection and split notices now go to new user mode `e`.
  These previously used user mode `x`.
* Services may now change the host of a specific user
  via `SVSMODE <timestamp> <target> +x <hostname>`


#### Noteworthy changes in version 8.0.6 (2013-01-28)
* Fix bug where idle time sometimes is 0 even if the client didn't
  send any private message
* Fixed possible core in `try_parse_v4_netmask`


#### Noteworthy changes in version 8.0.5 (2013-01-24)
* Nick and topic lengths are now configurable via `ircd.conf`.
  A `max_nick_length`, as well as a `max_topic_length` configuration option
  can now be found in the serverinfo {} block.
* Fixed build on GNU/Hurd
* Fixed log files not getting reopened after `REHASH`
* Improved logging of configuration file issues
* `ircd.pid` has been accidentally saved in `/var` instead of `/var/run`
* Linux RT signal support for notification of socket events has been dropped
* Fixed `STATS Y|y` sometimes sending weird sendq/recvq values
* `INFO` now also shows configured values of `disable_fake_channels`,
  and `stats_e_disabled`
* `m_webirc.c` is now officially supported, and has been moved from contrib/
  to modules/
* `WHOIS`, `STATS p`, and `TRACE` may now show fake idle times depending
  on how the new `class::min_idle` and `class::max_idle` configuration
  directives have been configured. This feature basically works in the
  same way as it does in csircd.
* The configuration parser now does support `year` and `month` units


#### Noteworthy changes in version 8.0.4 (2013-01-02)
* Fixed possible core on `USERHOST`/`ISON` with optimization enabled
* Fixed bug where `can_flood` sometimes didn't work as expected


#### Noteworthy changes in version 8.0.3 (2012-12-24)
* Fixed core on `UNDLINE`
* `XLINE`, `KLINE`, `RESV`, `DLINE`, `SQUIT`, and `KILL` now have the
  same default reason if no reason has been specified


#### Noteworthy changes in version 8.0.2 (2012-12-20)
* Minor updates to the build system
* Fixed broken `--enable-assert` configure switch
* Fixed bug where timed events stopped from working if the system's
  clock is running backwards
* `STATS q|Q` now shows how many times a resv {} block has been matched
* Fixed contributed `WEBIRC` module
* IRC operators may now again see server generated nick rejection notices


#### Noteworthy changes in version 8.0.1 (2012-11-04)
* Fixed broken CIDR support for `CHALLENGE` based IRC operator logins
* Fixed class limits not properly applying to operator {} blocks
* Fixed possible `TBURST` desynchronization with services
* Fixed `TBURST` from leaking the server name if it's a hidden server


#### Noteworthy changes in version 8.0.0 (2012-10-18)
* Fixed an off-by-one with spoofs. Spoofs are now also checked for
  invalid characters.
* Removed `general::use_whois_actually` configuration directive.
  This is now enabled by default
* Minor `SQUIT` handling fixes
* Fixed bancache not being updated on `CHGHOST`/`CHGIDENT`


#### Noteworthy changes in version 8.0.0rc1 (2012-09-28)
* Removed `general::client_flood` configuration option and added the
  new `recvq` configuration directive to class {} blocks.
  The max size of a receive queue can be seen in `STATS Y`
  for each class.
* Allow the `[` and `]` characters in server description


#### Noteworthy changes in version 8.0.0beta3 (2012-08-24)
* Fixed wrong syntax in several language files
* Removed &localchannels
* `PRIVMSG` to `opers@some.server` is no longer supported
* Fixed bug that could lead to topic desynchronization
* Removed `serverhide::disable_hidden` configuration option
* Dropped ircd-hybrid-6 `GLINE` compatibility mode
* Removed `use_invex`, `use_except` and `use_knock` configuration options.
  These features are now enabled by default.


#### Noteworthy changes in version 8.0.0beta2 (2012-07-21)
* `channel::disable_fake_channels` now also disables ascii 29 (mIRC italic)
  when set to `yes`
* Added `channel::max_chans_per_oper` configuration directive. The old way was to
  let IRC operators join three times the amount of `max_chans_per_user`.
* Replaced `MODLOAD`, `MODUNLOAD`, `MODRELOAD`, `MODLIST` and `MODRESTART`
  commands with the new `MODULE` command which can be fed with the `LOAD,`
  `UNLOAD`, `RELOAD` and `LIST` parameters.
  `MODRESTART` has been entirely removed. Use `MODULE RELOAD *` to reload
  all modules.
* Added back server notice when a client tries to obtain a reserved nick name
* Removed `OMOTD` module
* Added `set` to IRC operator privilege flags. Gives access to the `SET` command.
* Improved TS6 support
* Channel keys/passwords are now case sensitive


#### Noteworthy changes in version 8.0.0beta1 (2012-05-28)
* Implemented full services support, including but not limited to the
  following changes:
  - Added `SVSNICK`, and `SVSMODE` command handlers
  - Added service stamps to `NICK`/`UID` messages
  - Added SVS to server capabilities (`CAPAB`). SVS capable servers can
    deal with extended `NICK`/`UID` messages that contain service IDs/stamps.
  - Changed rejected client notices to go to new user mode `j`. These
    previously used user mode `r`.
  - Added user mode `r` (registered nick) and channel mode `r` (registered channel)
  - Added user mode `R` (only registered clients may send a private message)
  - Added channel mode `R` (only registered clients may join that channel)
  - Various services shortcuts have been added (`NS`, `CS`, `NICKSERV`, `CHANSERV`, etc.)
  - Added services {} block to `ircd.conf`
  - Added `services_name` directive to general {} block
  - Added `GLOBOPS` mainly for services compatibility, but can be used by IRC operators, too
* Removed `RKLINE` and `RXLINE` commands. Regular expression based bans should
  only be added via `ircd.conf`.
* Added `globops`, `restart`, `dline`, `undline` and `module` IRC operator privilege flags.
  Read `doc/reference.conf` for further explanation of what these flags control.
* Removed Idle-time klines
* Cleaned up modules API. Old modules won't work anymore
* Removed `general::burst_away` configuration directive. `AWAY` bursts are now
  controlled via `connect::flags` explicitly.
* Introduced new logging subsystem including log rotation based on
  file sizes. Log timestamp format is ISO8601 now.
* Added support for remote D-lines
* Added user mode `H` which is basically a replacement for the `hidden_admin` and
  `hidden_oper` operator flags. With user mode `H`, IRC operator status can now
  be hidden even on remote servers
* Added CIDR support for operator {} blocks
* Removed the servlink program. ircd-hybrid can now make use of
  SSL/TLS for inter-server communication.
  NOTE: compressed server links are of course still available, but a SSL/TLS
  connection is required, as compression is now handled via OpenSSL
* Removed `ssl_server_protocol` configuration directive and
  added `ssl_client_method` and `ssl_server_method` instead.
  Both of these options can now be changed at runtime.
* IRC operator login IDs are no longer limited to `NICKLEN*2`
* Removed `channel::burst_topicwho` configuration option. This feature is now
  enabled by default.
* `STATS Y|y` now reports CIDR limits as well
* Added `m_webirc.c` to `contrib/`
