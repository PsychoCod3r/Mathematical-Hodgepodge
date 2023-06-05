/**********************************
 * primes.c                       *
 * Clone of Primes program on the *
 * Telehack server                *
 * Author: Michael Warren         *
 * Date: Sun Nov 20 2022          *
 **********************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

struct prime{
	int num;
	struct prime *next;
};

struct prime *prime_ptr;
struct prime *base_ptr;

void free_list( int );

int main( int argc, char **argv ){
	int idx1 = 3;	// First index, number to test
	int idx2 = 0;	// Second index, number of primes tabulated
	bool isprime;
	bool has_printed;

	signal( SIGINT, free_list );
	signal( SIGQUIT, free_list );
	signal( SIGTERM, free_list );

	// Set up prime list:
	base_ptr = (struct prime *) malloc( sizeof( struct prime ) );
	prime_ptr = base_ptr;
	prime_ptr->next = (struct prime *) malloc( sizeof( struct prime ) );
	prime_ptr = prime_ptr->next;
	prime_ptr->num = 2;

	// Main loop:
	for(;;){
		// Test for primeness:
		isprime = true;
		prime_ptr = base_ptr;
		while( prime_ptr->next ){
			prime_ptr = prime_ptr->next;
			if( idx1 % prime_ptr->num == 0 ) isprime = false;
		}
		// Add prime and print:
		if( isprime ){
			prime_ptr->next = (struct prime *) malloc( sizeof( struct prime ) );
			prime_ptr->next->num = idx1;
			printf( "%d ", idx1 );
			fflush( stdout );
			idx2++;
			has_printed = false;
		}
		// Print next seven primes:
		if( idx2 % 7 == 0 && !has_printed ){
			putchar( '\n' );
			has_printed = true;
			sleep( 1 );
		}
		idx1++;
	}

	return 0;
}

// Free all structs in the prime list:
void free_list( int signum ){
	prime_ptr = base_ptr;
	while( prime_ptr->next ){
		prime_ptr = prime_ptr->next;
		free( base_ptr );
		base_ptr = prime_ptr;
	}
	free( prime_ptr );
	raise( signum );
}
