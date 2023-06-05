# Mathematical-Hodgepodge
Small programs or code snippets I wrote that demonstrate or implement mathematical concepts

## primes.c:

Generates a continuous sequence of successive prime numbers, displaying five at a time.

*Note: This program will continue running until its process is killed.*

## funcplot.r

This is a small R script containing a single function. That function is basically a proof of concept for higher order functions that take arbitrary functions as parameters. You give it any real-valued numerical function as input, either the name of an existing function or a lambda expression, and it will plot that function in Cartesian coordinates.

I didn't create a package for this, since I didn't thank that was warranted for a single function, but you can easily copy and paste it into your code or into the R REPL if you want to use it. There's also documentation of the function including examples of how to use a named function or a lambda in the man page titled funcplot.Rd. You can place this file in any man directory used by R and then type `?funcplot` to view the documentation.

## godel.c

This is a proof of concept for Gödel numbering. It's not finished yet, but when it's done, it will be able to encode any file as its Gödel number, using a product of prime numbers raised to the power of the 8-bit value stored in each byte. I also plan to create a decoder that will be able to recover a file from its Gödel number. Right now I've only managed to generate the terms of the Gödel number and store them in a text file. When the program is finished, these terms will be read from the file and multiplied together. Gödel numbers are huge, and can be hundreds or even thousands of digits. The program deals with this by using dc as a back-end to perform all the calculations, since dc is an arbitrary-precision calculator.
