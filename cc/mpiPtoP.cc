#include "mpi.h"
#include <stdio.h>
#include <string.h>

#define BUFLEN 512

int main (int argc, char *argv[])
{
    int myid, int numprocs, next ,namelen;
    char buffer[BUFLEN];
    MPI_Status status;
    
    MPI_Init(&argc, &argv);
    return (0);
}


