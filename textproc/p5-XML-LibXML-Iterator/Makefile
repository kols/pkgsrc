# $NetBSD: Makefile,v 1.22 2015/06/12 10:51:36 wiz Exp $
#

DISTNAME=	XML-LibXML-Iterator-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-LibXML-Iterator/
COMMENT=	Iterator for XML::LibXML parsed documents

DEPENDS+=	p5-XML-LibXML>=1.52:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-NodeFilter-[0-9]*:../../textproc/p5-XML-NodeFilter

PERL5_PACKLIST=	auto/XML/LibXML/Iterator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
