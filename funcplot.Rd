% File package/man/funcplot.Rd

\name{funcplot}
\alias{funcplot}
\title{Arbitrary Numerical Function Plotter}
\description{
	Plots a given single-variable real-valued function in Cartesian coordinates.
}
\usage{
funcplot( func, min, max, step )
}
\arguments{
	\item{func}{Function of format \code{function( numeric )}}
	\item{min}{Minimum x value}
	\item{max}{Maximum x value}
	\item{step}{Distance between sample points}
}
\value{none}
\examples{
funcplot( func = sqrt, min = 0, max = 10, step = 0.01 )
funcplot( func = function( x ){ x^2 - x^3 + 3*x - 2 }, min = -10, max = 10, step = 0.01 )
}
\author{
	Michael Warren
	\href{https://psychocod3r.wordpress.com/author/psychocod3r}{WordPress}
	\href{https://github.com/psychocod3r}{GitHub}
	\email{acidkicks@protonmail.com}
}
\keyword{dplot}
\keyword{math}
\keyword{graphs}
