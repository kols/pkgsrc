# $NetBSD: Makefile,v 1.6 2015/07/12 18:56:11 wiz Exp $

DISTNAME=	Data-Uniqid-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Uniqid/
COMMENT=	Perl extension for simple generaion of unique ids
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=  {perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Data/Uniqid/.packlist

.include "../../mk/bsd.prefs.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
