# $Id$

%{!?ircd_uid:%define ircd_uid 79}
%{!?ircd_gid:%define ircd_gid 79}
%{!?ircd_dir:%define ircd_dir /usr/local/ircd}

Summary: IRCD-Hybrid - Internet Relay Chat server
Name: ircd-hybrid
Version: 7.2.0
Release: 1
License: GPL
Group: System Environment/Daemons
URL: http://www.ircd-hybrid.org/
Source: %{name}-%{version}.tgz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root
BuildPrereq: gcc, binutils, glibc-devel
Provides: ircd

%description
IRCD-Hybrid is an Internet Relay Chat server

%package devel
Group: Development/Libraries
Summary: include files for building IRCD-Hybrid modules

%description devel
include files for building IRCD-Hybrid modules

%package doc
Group: System Environment/Daemons
Summary: additional documentation for IRCD-Hybrid

%description doc
additional documentation for IRCD-Hybrid

%prep
%setup -q -n %{name}-%{version}

%build
%configure \
  --prefix=%{ircd_dir} \
  --exec_prefix=%{ircd_dir} \
  --bindir=%{ircd_dir}/bin \
  --sysconfdir=%{ircd_dir}/etc \
  --localstatedir=%{ircd_dir}


make CFLAGS="$RPM_OPT_FLAGS" %{?_smp_mflags}

%install
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{ircd_dir}
mkdir -p $RPM_BUILD_ROOT/etc/init.d
make install DESTDIR=$RPM_BUILD_ROOT
sed -e "s|@bindir@|%{ircd_dir}/bin|g" \
    -e "s|@sysconfdir@|%{ircd_dir}/etc|g" \
    contrib/ircd.init.in > $RPM_BUILD_ROOT/etc/init.d/ircd
chmod 755 $RPM_BUILD_ROOT/etc/init.d/ircd
rm -rf $RPM_BUILD_ROOT/%{ircd_dir}/etc/*
mkdir -p $RPM_BUILD_ROOT/%{_docdir}/%{name}-%{version}
cp -p LICENSE README.FIRST RELNOTES INSTALL $RPM_BUILD_ROOT/%{_docdir}/%{name}-%{version}
cp -pr doc $RPM_BUILD_ROOT/%{_docdir}/%{name}-%{version}
cp -fp etc/*.conf* $RPM_BUILD_ROOT/%{_docdir}/%{name}-%{version}/doc
cp -p etc/simple.conf $RPM_BUILD_ROOT/%{ircd_dir}/etc/ircd.conf.simple
rm -rf $RPM_BUILD_ROOT/%{_docdir}/%{name}-%{version}/doc/old

%clean
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

%pre
/usr/sbin/groupadd -f -g %{ircd_gid} ircd 2> /dev/null || :
/usr/sbin/useradd -c "IRCD" -u %{ircd_uid} -g ircd \
        -s /bin/false -r -d %{ircd_dir} ircd 2> /dev/null || :

%post
/sbin/chkconfig --add ircd
cd %{ircd_dir}/etc
for i in cresv.conf dline.conf kline.conf nresv.conf xline.conf ; do
	if [ ! -f "$i" ] ; then
		touch $i
		chown ircd:ircd $i
	fi
done
if [ ! -f ircd.motd ] ; then
	echo "Welcome to ircd-hybrid!  This is the Message of the Day" > ircd.motd
fi
if [ ! -f ircd.conf ] ; then
	sed \
	-e "s/irc.example.com/`hostname`/" \
	-e "s/_CHANGE_ME_/9ZZ/" \
	ircd.conf.simple > ircd.conf
fi

%preun
if [ $1 = 0 ]; then
 /sbin/service ircd stop > /dev/null 2>&1
 /sbin/chkconfig --del ircd
fi
  

%files
%defattr(-,root,root)
%{ircd_dir}/bin
%dir %attr(700,ircd,ircd) %{ircd_dir}/etc
%attr(600,ircd,ircd) %{ircd_dir}/etc/ircd.conf.simple
%attr(700,ircd,ircd) %{ircd_dir}/logs
%{ircd_dir}/modules
%{_mandir}
/etc/init.d/ircd
%{_docdir}/%{name}-%{version}/LICENSE
%{_docdir}/%{name}-%{version}/README.FIRST
%{_docdir}/%{name}-%{version}/RELNOTES
%{_docdir}/%{name}-%{version}/INSTALL

%files devel
%defattr(-,root,root)
%{_includedir}

%files doc
%defattr(-,root,root)
%{_docdir}/%{name}-%{version}/doc
