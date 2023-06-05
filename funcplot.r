#!/usr/bin/Rscript

# Plot an arbitrary real-valued, single-variable
# function
funcplot <- function( func, min, max, step ){
	x <- seq( from = min, to = max, by = step )
	y <- seq( from = min, to = max, by = step )

	for( i in 1:length( y ) ){
		y[i] <- func( x[i] )
	}

	plot( x, y, type = "l" )
}

