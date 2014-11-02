#include "mpich-x86_64/mpi.h"
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXN 10000
#define PMAX 10000
#define BUFLEN 512

int main(int argc, char **argv)
{
    int myid, numprocs;
    int namelen, next;
    char buffer[BUFLEN];
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    printf("Process %d of %d\n", myid, numprocs);
    memset(buffer, 0, BUFLEN*sizeof(char));

    if(myid == numprocs - 1)
        next = 0;
    else
        next = myid+1;

    if(myid == 0) 
    {
        strcpy(buffer, "hello there");
        printf("%d sending '%s' \n", myid, buffer);
        fflush(stdout);
        MPI_Send(buffer, strlen(buffer)+1, MPI_CHAR, next ,99 ,MPI_COMM_WORLD);
        printf("%d receiving... \n", myid);
        fflush(stdout);
        MPI_Recv(buffer, BUFLEN, MPI_CHAR, MPI_ANY_SOURCE, 99, MPI_COMM_WORLD, &status);
        printf("%d received '%s' \n", myid, buffer);
        fflush(stdout);
    }
    else
    {
        printf("%d receiving...\n", myid);
        fflush(stdout);
        MPI_Recv(buffer, BUFLEN, MPI_CHAR, MPI_ANY_SOURCE, 99, MPI_COMM_WORLD, &status);
        printf("%d received '%s' \n", myid, buffer);
        fflush(stdout);
        MPI_Send(buffer, strlen(buffer)+1, MPI_CHAR, next, 99, MPI_COMM_WORLD);
        printf("%d sent '%s'\n", myid, buffer);
        fflush(stdout);
    }
    
    MPI_Get_processor_name(processor_name, &namelen);
    fprintf(stderr, "Hello world! Processor %d of %d on %s\n", myid, numprocs, processor_name);

    MPI_Finalize();
    return 0;
}

