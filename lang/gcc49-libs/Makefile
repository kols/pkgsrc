# $NetBSD: Makefile,v 1.5 2015/11/25 12:51:17 jperkin Exp $

GCC_PKGNAME=	gcc49
.include	"../../lang/${GCC_PKGNAME}/version.mk"

DISTNAME=	gcc-${GCC49_DIST_VERSION}
PKGNAME=	${GCC_PKGNAME}-libs-${GCC49_DIST_VERSION}

## The PKGREVISION of this package needs to be at least 1 more than the
## PKGREVISION of the lang/gcc49 package so that with the dependence pattern
## '{gcc49,gcc49-libs}>=4.9.*' pkg_add will choose gcc49-libs over gcc49.
PKGREVISION=	1

CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) support shared libraries
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_TOOLS+=	pax

NO_BUILD=	yes
CHECK_SHLIBS=	no

## Depend on exactly ${GCC49_DIST_VERSION}.
BUILD_DEPENDS+=		${GCC_PKGNAME}-${GCC49_DIST_VERSION}{,nb[0-9]*}:../../lang/gcc49

.include "../../mk/bsd.prefs.mk"

LIBGCC_SUBPREFIX=	${GCC_PKGNAME}
LIBGCC_PREFIX=		${LOCALBASE}/${LIBGCC_SUBPREFIX}
GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}
BUILD_DEFS+=		GCC_TARGET_MACHINE

.include "../../mk/bsd.prefs.mk"
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SHLIB_EXT=	dylib
.else
SHLIB_EXT=	so
.endif

LIBRARY_FILES=	${WRKDIR}/lib_files

GENERATE_PLIST+= ${SED} -e 's,^,${LIBGCC_SUBPREFIX}/${GCC_TARGET_MACHINE}/,' \
			${LIBRARY_FILES};
GENERATE_PLIST+= ${GREP} -q 'lib/' ${LIBRARY_FILES} || \
	   ${ECHO} '@pkgdir ${LIBGCC_SUBPREFIX}/${GCC_TARGET_MACHINE}/lib' ;

${LIBRARY_FILES}:
	${PKG_INFO} -qL '${GCC_PKGNAME}-${GCC49_DIST_VERSION}*' |		\
	${SED} -n -e's,^${LIBGCC_PREFIX}/,,' -e'/libexec\//d'		\
		-e'/libgij/d;/libgcj/d;/libjvm/d'			\
		-e'/lib.*\.${SHLIB_EXT}/p' 		>${LIBRARY_FILES}

do-install: ${LIBRARY_FILES}
	${TEST} -d ${DESTDIR}${LIBGCC_PREFIX}/${GCC_TARGET_MACHINE}/lib ||	\
		${MKDIR} ${DESTDIR}${LIBGCC_PREFIX}/${GCC_TARGET_MACHINE}/lib
	cd ${LIBGCC_PREFIX} && 						\
	  ${PAX} -rw ${DESTDIR}${LIBGCC_PREFIX}/${GCC_TARGET_MACHINE} <${LIBRARY_FILES}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
