#include <../include/minix/callnr.h>
#include <../include/lib.h>
#include <../include/stdio.h>
#include <../include/stdlib.h>
#include <../include/string.h>

int getprocnr(int pid)
{
    message mes;
    mes.m1_i1 = pid;
    return _syscall(MM, GETPROCNR, &mes); /*_PROTOTYPE( int _syscall, (int _who, int _syscallnr, message *_msgptr)	);
    MM -> Serwer number (MM or FS)
    GETPROCNR -> Numer wywołania systemowego (podmienia na 46)
    &mes -> Wkaźnik na strukturę message z danymi do wywołania (wstawiliśmy jako pierwsze PID)*/
}


int main(int argc, char** argv)
{
    int process_id = atoi(argv[1]), current_process_number, counter;

    if(argc != 2) return -1;

    for(counter = process_id; counter < process_id + 10; counter++)
    {
        current_process_number = getprocnr(counter);

        if(current_process_number > 0) printf("PID: %d, IDX: %d\n", counter, current_process_number);
        else printf("PID: %d, ERR: %d\n", counter, errno);
    }

    return 0;
}