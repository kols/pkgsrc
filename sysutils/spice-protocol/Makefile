# $NetBSD: Makefile,v 1.5 2015/09/30 20:13:29 wiz Exp $

DISTNAME=	spice-protocol-0.12.10
CATEGORIES=	sysutils
MASTER_SITES=	http://spice-space.org/download/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://spice-space.org/
COMMENT=	Headers defining protocols for SPICE server code
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	spice-protocol.pc.in
REPLACE_PYTHON+=	python_modules/*.py *.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
