# $NetBSD: Makefile,v 1.8 2013/03/02 20:33:29 wiz Exp $

DISTNAME=	barnyard-0.2.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=barnyard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.snort.org/
COMMENT=	Fast output system for snort

GNU_CONFIGURE=		YES

PKG_SYSCONFSUBDIR=	snort

LIBS.SunOS+=	-lresolv

CONF_FILES=	${EGDIR}/barnyard.conf ${PKG_SYSCONFDIR}/barnyard.conf

EGDIR=		${PREFIX}/share/examples/barnyard

INSTALLATION_DIRS=	bin share/doc/barnyard share/examples/barnyard

.include "options.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/barnyard ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ \
		${DESTDIR}${PREFIX}/share/doc/barnyard/FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/USAGE \
		${DESTDIR}${PREFIX}/share/doc/barnyard/USAGE
	${INSTALL_DATA} ${WRKSRC}/etc/barnyard.conf \
		${DESTDIR}${EGDIR}/barnyard.conf

.include "../../mk/bsd.pkg.mk"
