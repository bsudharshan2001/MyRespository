// LabEvaluation-1.cpp 
//Program Done By: B Sudharshan - CB.EN.U4CSE19008 - CSE A
// SET - 1


//Question - 1 :
/*
#include <mpi.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    MPI_Status status;
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    /*char msg1 = 'T1';
    char msg2 = 'T2';
    char msg4 = 'T4';
    char msg3 = 'T3';*/
/*
    int T1 = 1, T2 = 2, T3 = 3, T4 = 4, msg = 19008, buffer;

    if (world_rank == 0)
    {
        //Receiveing the messages from Odd and Even Ranks/Nodes
        for (int i = 1; i < world_size; i++)
        {
            if (i % 2 == 0)
                MPI_Send(&msg, sizeof(int), MPI_INT, i, T2, MPI_COMM_WORLD);
            else
                MPI_Send(&msg, sizeof(int), MPI_INT, i, T1, MPI_COMM_WORLD);
        }
        for (int j = 1; j < world_size; j++)
        {
            MPI_Recv(&buffer, sizeof(int), MPI_INT, j, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            printf("This is the process of rank %d, Received : %d with the following TAG: %d\n", j, buffer, status.MPI_TAG);
        }
    }
    //For Nodes with even rank
    else if (world_rank % 2 == 0)
    {
        //Sending the message TAG T4 to the master
        MPI_Recv(&buffer, sizeof(int), MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        printf("This is the process of rank %d, Received : %d with the following TAG: %d ----> TAG T4\n", world_rank, buffer, status.MPI_TAG);
        printf("Sending TAG T4 to Master\n");
        MPI_Send(&buffer, sizeof(int), MPI_INT, 0, T4, MPI_COMM_WORLD);
    }
    //For Nodes with Odd ranks
    else
    {
        //Sending the message TAG T3 to the master

        MPI_Recv(&buffer, sizeof(int), MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        printf("This is the process of rank %d, Received : %d with the following TAG: %d ----> TAG T3\n", world_rank, buffer, status.MPI_TAG);
        printf("Sending TAG T3 to Master\n");
        MPI_Send(&buffer, sizeof(int), MPI_INT, 0, T3, MPI_COMM_WORLD);
    }

    // Finalize the MPI environment.
    MPI_Finalize();

}
*/


#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

// size of array
#define n 8

int a[] = { 5,8,2,10,11,16,22,23 };
int b[] = { 8,9,7,6,5,4,3,2 };

int x[1000];
int y[1000];

int main(int argc, char* argv[])
{

    int world_rank, world_size,elements_per_process,n_elements_recieved;
    // world_size -> no. of processes
    // world_rank -> process id

    MPI_Status status;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // master process
    if (world_rank == 0) {
        int index, i;
        elements_per_process = n / world_size;

        if (world_size > 1) {

            for (i = 1; i < world_size - 1; i++) {
                index = i * elements_per_process;

                MPI_Send(&elements_per_process, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
                MPI_Send(&a[index],elements_per_process, MPI_INT, i, 0, MPI_COMM_WORLD);
                MPI_Send(&b[index],elements_per_process,MPI_INT, i, 0,MPI_COMM_WORLD);
            }

            index = i * elements_per_process;
            int left = n - index;

            MPI_Send(&left,1, MPI_INT,i, 0,MPI_COMM_WORLD);
            MPI_Send(&a[index],left, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&b[index],left,MPI_INT, i, 0,MPI_COMM_WORLD);
        }

        int sum = 0;
        for (i = 0; i < elements_per_process; i++)
            sum += a[i] * b[i];

        int tmp;
        for (i = 1; i < world_size; i++) {
            MPI_Recv(&tmp, 1, MPI_INT,MPI_ANY_SOURCE, 0,MPI_COMM_WORLD, &status);
            int sender = status.MPI_SOURCE;
            sum += tmp;
        }

        printf("The Calculated dot product of the given iworld_sizeut is : %d\n", sum);
    }

    else {
        MPI_Recv(&n_elements_recieved, 1, MPI_INT, 0, 0,MPI_COMM_WORLD,&status);
        MPI_Recv(&x, n_elements_recieved,MPI_INT, 0, 0,MPI_COMM_WORLD,&status);
        MPI_Recv(&y, n_elements_recieved,MPI_INT, 0, 0, MPI_COMM_WORLD,&status);

        int partial_sum = 0;
        for (int i = 0; i < n_elements_recieved; i++)
            partial_sum += x[i] * y[i];

        MPI_Send(&partial_sum, 1, MPI_INT,0, 0, MPI_COMM_WORLD);
    }

    // Finalize the MPI environment.
    MPI_Finalize();

    return 0;
}