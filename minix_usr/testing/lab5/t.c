/* t.c - polecenie t wyswietla liczbe i rozmiary blokow wolnych */
#include <stdio.h>
#include <unistd.h>
#include <lib.h>
                                                                                
PUBLIC int hole_map( void *buffer, size_t nbytes)
{
        message mes;
        mes.m1_i1 = nbytes; //basing on size of buffer
        mes.m1_p1 = buffer; //passing on buffer pointer
        return _syscall(MM, WORST_FIT, &mes);
	/* ... _syscall(..HOLE_MAP..) ... */
}
                                                                                
int
main( void )
{
        unsigned int    b[1024];
        unsigned int    *p, a, l;
        int     res;

		res = hole_map( b, sizeof( b ) );
        printf( "[%d]\t", res );
        p = b;
        while( *p )
        {
                l = *p++;
                a = *p++; /* tu niewykorzystywane */
                printf( "%d\t", l );
        }
        printf( "\n" );
        return 0;
}