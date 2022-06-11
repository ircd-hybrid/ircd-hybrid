## ircd-hybrid installation instructions

1.  Read the `NEWS.md` file to find out about the exciting new features in this
    version. Other good reads are `doc/reference.conf`, and `README.md`.

2.  Run the configure script. It will create `config.h` and the
    Makefiles to match your system. The paths are now handled
    with the `--prefix` option to configure.
    `/usr/local/ircd` is the default if no prefix is specified.

    `./configure --prefix=/usr/local/ircd`

    The script will determine whichever of the following is best for
    your system, but you may (unsupported) force their usage with
    undefined results:

       * `--enable-kqueue` - Use the superior kqueue(2) system call as
         opposed to the default poll(2). This is currently only available
         on FreeBSD, OpenBSD, NetBSD, DragonFly BSD and macOS

       * `--enable-epoll` - Enables epoll(4) Signal I/O system. This is
         currently only available on 2.5.44 Linux kernel versions or
         later.

       * `--enable-poll` - Use POSIX poll(2).

       Incidentally, the order of listing above is the order of auto-
       detection in configure. So if you do have kqueue but wish to
       enable poll(2) instead (bad idea), you must use `--enable-poll`.

       * `--with-tls=` - Controls TLS (Transport Layer Security) support.
         Supported options are currently `openssl`, `wolfssl`, `gnutls`,
         and `none`.

         If nothing has been specified, configure tries to autodetect in the
         following order: openssl/libressl -> gnutls -> wolfssl.


    These are optional or have default values that may be overridden:

       * `--enable-assert` - Enable use of numerous debugging checks. This is
         considered a developer-only feature and should not be used on any
         production servers for maximum speed so as to prevent cores from
         things that shouldn't normally happen.

       * `--enable-debugging` - Prepares Makefiles to compile the ircd sources
         with proper settings that are required for debugging purposes.
         This switch basically sets `CFLAGS` to `-g -O0`.

       * `--enable-efence` - Allows easy linking with the electric fence memory
         debugger library.


3.  Run `make`; this should build the ircd.

4.  Run `make install`; this will install the server, modules, and tools in the
    path with the prefix specified when configure was ran.
