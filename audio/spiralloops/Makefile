# $NetBSD: Makefile,v 1.39 2015/04/25 14:20:24 tnn Exp $
#

DISTNAME=		SpiralLoops-2.0.0
PKGNAME=		spiralloops-2.0.0
PKGREVISION=		10
CATEGORIES=		audio
MASTER_SITES=		http://www.pawfal.org/Software/SpiralLoops/dload/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pawfal.org/Software/SpiralLoops/
COMMENT=		Loop based sampler

# only runs correctly on little-endian machines
BROKEN_EXCEPT_ON_PLATFORM=	${LITTLEENDIANPLATFORMS}

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
MAKE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:Q}
CXXFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CXXFLAGS+=		-DFLTK_1_0_COMPAT
CXXFLAGS.SunOS+=	-DSOUND_PCM_WRITE_CHANNELS=SNDCTL_DSP_CHANNELS

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralLoops ${DESTDIR}${PREFIX}/bin

.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
