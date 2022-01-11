// Lab2-Code4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char** argv)
{
    MPI_Init(&argc, &argv);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    if (world_size < 2)
    {
        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    int number;
    if (world_rank == 0)
    {
        number = -1;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("----- Process 0 says Hi! ----");
    }
    else if (world_rank == 1)
    {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("----- Process 1 says Hi! ----");
    }
    MPI_Finalize();
    return 0;
}

