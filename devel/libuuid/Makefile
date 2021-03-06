# $NetBSD: Makefile,v 1.16 2015/11/13 11:52:50 wiz Exp $

DISTNAME=	util-linux-2.27.1
PKGNAME=	${DISTNAME:S/util-linux/libuuid/}
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux/v2.27/
EXTRACT_SUFX=	.tar.xz
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/karelzak/util-linux
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

USE_GCC_RUNTIME=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-ncurses

PKGCONFIG_OVERRIDE+=	libuuid/uuid.pc.in

BUILD_TARGET=		libuuid.la libuuid/uuid.pc
INSTALLATION_DIRS+=	include/uuid lib/pkgconfig ${PKGMANDIR}/man3
CONFIG_SHELL=		bash
USE_TOOLS+=		bash:build

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./libuuid/src/libuuid.sym
.endif

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libuuid.la \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libuuid/src/uuid.h \
		${DESTDIR}${PREFIX}/include/uuid/uuid.h
	${INSTALL_DATA} ${WRKSRC}/libuuid/uuid.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig/uuid.pc
	set -e; for f in ${WRKSRC}/libuuid/man/*.3; do \
		${INSTALL_MAN} $${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/; \
	done

.include "../../mk/bsd.pkg.mk"
