# $NetBSD: Makefile,v 1.10 2015/06/12 10:49:47 wiz Exp $
#

DISTNAME=	Test-Assertions-1.054
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Assertions/
COMMENT=	Perl 5 module prodiving building blocks for unit and runtime testing
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl	# for test target
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Assertions/.packlist

DEPENDS+=	p5-Log-Trace-[0-9]*:../../devel/p5-Log-Trace

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
