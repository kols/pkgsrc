# $NetBSD: Makefile,v 1.3 2015/10/01 21:38:44 kamil Exp $

DISTNAME=	logswan-1.01
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logswan.org
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	modified-bsd

USE_CMAKE=	yes

SUBST_CLASSES+=		geoip
SUBST_STAGE.geoip=	post-patch
SUBST_FILES.geoip+=	src/logswan.c
SUBST_SED.geoip+=	-e 's,/usr/local,${PREFIX},g'

DOCDIR=		share/doc/logswan
EGDIR=		share/examples/logswan

CONF_FILES+=	${EGDIR}/logswan.json ${PKG_SYSCONFDIR}/logswan.json

AUTO_MKDIRS=	yes

post-install:
.for f in AUTHORS README.md THANKS TODO
	${RUN}${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	${RUN}${INSTALL_DATA} ${WRKSRC}/examples/logswan.json \
	                      ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../textproc/jansson/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
