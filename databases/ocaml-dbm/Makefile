# $NetBSD: Makefile,v 1.9 2015/08/07 11:20:32 jaapb Exp $
#

PKGNAME=	ocaml-dbm-${VERSION}
DISTNAME=	camldbm-${VERSION}
VERSION=	1.0
PKGREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/728/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://camldbm.forge.ocamlcore.org/
COMMENT=	OCaml binding to the NDBM and GDBM database library
LICENSE=	gnu-lgpl-v2

CONFLICTS=	ocaml-findlib<1.4nb1

HAS_CONFIGURE=	yes
MAKE_ENV+=	DESTDIR="${DESTDIR}"

INSTALLATION_DIRS=	lib/ocaml/stublibs lib/ocaml/site-lib/dbm

post-install:
	${INSTALL_DATA} ${WRKSRC}/META ${DESTDIR}${PREFIX}/lib/ocaml/site-lib/dbm

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
