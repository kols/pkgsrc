# $NetBSD: Makefile,v 1.5 2015/06/12 10:49:11 wiz Exp $

DISTNAME=	ExtUtils-InstallPaths-0.011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-InstallPaths/
COMMENT=	Build.PL install path logic made easy
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-Config>=0.002:../../devel/p5-ExtUtils-Config

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils/InstallPaths/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
