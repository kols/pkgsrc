# $NetBSD: Makefile,v 1.40 2015/09/23 12:00:11 joerg Exp $

DISTNAME=	ScientificPython-2.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python//}
CATEGORIES=	math python
MASTER_SITES=	http://sourcesup.cru.fr/frs/download.php/4411/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirac.cnrs-orleans.fr/ScientificPython/
COMMENT=	Python modules for scientific computing

CONFLICTS+=	py-Scientific-[0-9]*

MAKE_ENV+=	NETCDF_PREFIX=${BUILDLINK_PREFIX.netcdf}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PLIST_SUBST+=	OSNAME=${LOWER_OPSYS:S/solaris/sunos/}
PLIST_SUBST+=	OSVER=${OS_VERSION:C/^(.).*/\1/}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.8.1

INSTALLATION_DIRS=	bin

post-build:
	${RUN} cd ${WRKSRC}/Src/MPI && ${SETENV} CFLAGS=${CFLAGS:Q} \
	  LDFLAGS="${LDFLAGS} ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}" ${PYTHONBIN} compile.py

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython \
		${DESTDIR}${PREFIX}/bin/mpipython${PYVERSSUFFIX}

.include "../../devel/netcdf/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
