# $NetBSD: Makefile,v 1.9 2015/10/01 13:16:53 richard Exp $

DISTNAME=	relatorio-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/r/relatorio/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relatorio.tryton.org/
COMMENT=	Templating library able to output odt and pdf files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pycha-[0-9]*:../../graphics/py-pycha
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=		#none
PYTHON_VERSIONED_DEPENDENCIES=	cairo
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2 via py-pycha

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
