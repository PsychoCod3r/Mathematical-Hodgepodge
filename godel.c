#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

struct prime{
	int64_t num;
	struct prime *next;
};

int main( int argc, char **argv ){
	int fd;
	if( argv[1] ){
		if( (fd = open( argv[1], O_RDONLY )) <= 2 ){
			fprintf( stderr, "%s: %s: %s\n", argv[0], argv[1], strerror( errno ) );
			exit( errno );
		}
	}
	else fd = 0;
	char charbuf[1];
	char *cmdbuf = (char *) calloc( 1, 256 );
	int size = 256;
	// Set up linked list for prime numbers:
	struct prime *head = (struct prime *) calloc( 1, sizeof( struct prime ) );
	struct prime *cur = head;
	int64_t p = 1;
	int i = 1;
	// Read file and calculate Godel terms:
	while( read( fd, charbuf, 1 ) ){
		// Calculate next prime
		bool is_prime = false;
		do{
			p++;
			// Test for primeness:
			is_prime = true;
			cur = head;
			while( cur->next ){
				cur = cur->next;
				if( !(p % cur->num) ){
					is_prime = false;
				}
			}
		} while( !is_prime );
		cur->next = (struct prime *) calloc( 1, sizeof( struct prime ) );
		cur->next->num = p;
		// Resize the buffer until it's large enough to hold the command string.
		while( true ){
			for( int i = 0; i < size; i++ ) cmdbuf[i] = '\0';
			snprintf( cmdbuf, size, "dc --expression=\"%ld %d ^ p\" >> dc.out", p , charbuf[0] );
			if( cmdbuf[size-1] == '\0' ) break;
			size <<= 1;
			cmdbuf = (char *) realloc( cmdbuf, size );
		}
		system( cmdbuf );
		system( "echo >> dc.out" );
		i++;
	}
	if( fd ) close( fd );
	// Free dynamically allocated memory:
	cur = head;
	while( cur->next ){
		cur = cur->next;
		free( head );
		head = cur;
	}
	free( cur );
	free cmdbuf;
	return 0;
}
