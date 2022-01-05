/* w.c - polecenie w przyjmuje jako argument 1 albo 0 */
/* wlaczajac/wylaczajac algorytm worst fit w systemie Minix */
#include <stdlib.h>
#include <unistd.h>
#include <lib.h>
#include <../../include/minix/callnr.h>


PUBLIC int worst_fit( int w )
{
    message mes;
    mes.m1_i1 = w; //basing on w, the worst fit will change or not...
    return _syscall(MM, WORST_FIT, &mes);
	/* ... _syscall(..WORST_FIT..) ... */
}

int
main( int argc, char *argv[] )
{
	if( argc < 2 )
		return 1;
	worst_fit( atoi( argv[1] ) );
	return 0;
}