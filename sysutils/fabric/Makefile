# $NetBSD: Makefile,v 1.40 2015/10/03 22:56:21 rodent Exp $

VERSION=		1.10.2
DISTNAME=		Fabric-${VERSION}
PKGNAME=		${DISTNAME:S/F/f/}
CATEGORIES=		sysutils net
MASTER_SITES=		http://pypi.python.org/packages/source/F/Fabric/

MAINTAINER=		gls@NetBSD.org
HOMEPAGE=		http://fabfile.org/
COMMENT=		Simple Pythonic remote deployment tool
LICENSE=		2-clause-bsd

DEPENDS+=		${PYPKGPREFIX}-paramiko>=1.10.0:../../security/py-paramiko

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # no support yet

USE_TOOLS+=		pax

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/fabric
INSTALLATION_DIRS+=	share/doc/fabric/api
INSTALLATION_DIRS+=	share/doc/fabric/api/contrib
INSTALLATION_DIRS+=	share/doc/fabric/api/core
INSTALLATION_DIRS+=	share/doc/fabric/changes
INSTALLATION_DIRS+=	share/doc/fabric/usage

post-install:
	${INSTALL_MAN} files/fab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

	cd ${WRKSRC}/sites/docs && pax -wr -pma *.rst api/contrib/*.rst \
		api/core/*.rst usage/* \
		${DESTDIR}${PREFIX}/share/doc/fabric/.
	cd ${WRKSRC}/sites/www && pax -wr -pma *.rst \
		${DESTDIR}${PREFIX}/share/doc/fabric/.

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
