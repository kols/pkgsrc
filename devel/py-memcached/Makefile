# $NetBSD: Makefile,v 1.5 2015/04/03 15:13:19 rodent Exp $

DISTNAME=	python-memcached-1.54
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.tummy.com/pub/python-memcached/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.tummy.com/Community/software/python-memcached/
COMMENT=	Python memcached client
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

DOCDIR=			${PREFIX}/share/doc/py-memcached
INSTALLATION_DIRS=	${DOCDIR}
REPLACE_PYTHON+=	memcache.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.53

post-install:
	${INSTALL_DATA} ${WRKSRC}/memcache.html ${DESTDIR}${DOCDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
