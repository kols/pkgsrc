# $NetBSD: Makefile,v 1.17 2015/08/06 09:06:29 wiz Exp $

DISTNAME=	File-DesktopEntry-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-DesktopEntry/
COMMENT=	Perl module for handling .desktop files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-BaseDir>=0.03:../../devel/p5-File-BaseDir

PERL5_PACKLIST=		auto/File/DesktopEntry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
