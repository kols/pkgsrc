# $NetBSD: Makefile,v 1.72 2015/10/10 01:58:20 ryoon Exp $

PKGNAME=	${APACHE_PKG_PREFIX}-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--disable-mod-activation
CONFIGURE_ARGS+=	--with-apache-libexecdir

APACHE_MODULE=		YES

BUILD_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

CFLAGS.SunOS+=		-D__EXTENSIONS__

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

PKG_APACHE_ACCEPTED=	apache22 apache24

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
