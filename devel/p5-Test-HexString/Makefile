# $NetBSD: Makefile,v 1.9 2015/06/12 10:49:49 wiz Exp $
#

DISTNAME=		Test-HexString-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-HexString/
COMMENT=		Perl5 module to test binary strings with hex dump diagnostics
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/HexString/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
