// LabAssignment-1.cpp 
// Program done by: B Sudharshan - CB.EN.U4CSE19008 - CSE A
// Athota Surya - CB.EN.U4CSE19007 - CSE A

//Question 1 - Point-to-Point Communication between Node 1 and Node 0
/*
#include <mpi.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0)
    {
        int x[4];
        //Receiveing only 4 elements out of 8 in y (Sent from node 1)
        MPI_Recv(x, 4, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (int i = 0; i < 4; i++)
            cout<<x[i]<< "  ";
    }
    else
    {
        int y[8] = {6,3,2,11,14,15,9,4};
        //Sending y to node 0
        MPI_Send(y, 4, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}
*/
// LabAssignment-1.cpp 
// Program done by: B Sudharshan - CB.EN.U4CSE19008 - CSE A
// Athota Surya - CB.EN.U4CSE19007 - CSE A

//Question 2 - Point-to-Point Communication between N Nodes
/*
#include <mpi.h>
#include <stdio.h>
#include<iostream>
using namespace std;
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int i;
    //There are total of 5 nodes (n=5)
    //Initiated variables to calculate the accumulated sum in each of the 5 nodes
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum;
    if (world_rank == 0)
    {
        for (i = 1; i <= 200; i++)
        {
            sum1 = sum1 + i;
        }
        MPI_Recv(&sum2, 1, MPI_INT, 1, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum3, 1, MPI_INT, 2, 7, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum4, 1, MPI_INT, 3, 8, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum5, 1, MPI_INT, 4, 9, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum = sum1 + sum2 + sum3 + sum4 + sum5;
        printf("This is the parent process of rank %d amoong %d ,The accumulated sum is: %d", world_rank, world_size, sum);
    }
    //If it is the 2nd Node
    //This Node calculates the sum between 201 and 400
    else if (world_rank==1)
    {
        for (i = 201; i <= 400; i++)
            sum2 = sum2 + i;
        MPI_Send(&sum2, 1, MPI_INT, 0, 6, MPI_COMM_WORLD);
        printf("This is node/rank %d processing the sum between numbers 201 and 400, which is: =>%d to node/rank 0", world_rank, sum2);

    }
    //If it is the 3rd Node
    //This Node calculates the sum between 401 and 600
    else if (world_rank==2)
    {
        for (i = 401; i <= 600; i++)
            sum3 = sum3 + i;
        MPI_Send(&sum3, 1, MPI_INT, 0, 7, MPI_COMM_WORLD);
        printf("This is node/rank %d processing the sum between numbers 401 and 600, which is: =>%d to node/rank 0", world_rank, sum3);
    }
    //If it is the 4th Node
    //This Node calculates the sum between 601 and 800
    else if (world_rank==3)
    {
        for (i = 601; i <= 800; i++)
            sum4 = sum4 + i;
        MPI_Send(&sum4, 1, MPI_INT, 0, 8, MPI_COMM_WORLD);
        printf("This is node/rank %d processing the sum between numbers 601 and 800, which is: =>%d to node/rank 0", world_rank, sum4);
    }
    //If it is the 5th Node
    //This Node calculates the sum between 801 and 1000
    else if (world_rank==4)
    {
        for (i = 801; i <= 1000; i++)
            sum5 = sum5 + i;
        MPI_Send(&sum5, 1, MPI_INT, 0, 9, MPI_COMM_WORLD);
        printf("This is node/rank %d processing the sum between numbers 801 and 1000, which is: =>%d to node/rank 0", world_rank, sum5);
    }
    MPI_Finalize();

}
*/
/*
#include <mpi.h>
#include <stdio.h> 
#include <stdlib.h> 
int main(int argc, char** argv)
{
    int world_rank;
    int world_size;
    int token;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // Receive from the lower process and send to the higher process... 
    if (world_rank != 0) {
        MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received token %d from process%d\n", world_rank, token, world_rank - 1);
    }
    else {
        token = -1;
    }
    MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
    if (world_rank == 0)
    {
        MPI_Recv(&token, 1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received token %d from process %d\n", world_rank, token, world_size - 1);
    }
    MPI_Finalize();
}
*/
// LabAssignment-1.cpp 
// Program done by: B Sudharshan - CB.EN.U4CSE19008 - CSE A
// Athota Surya - CB.EN.U4CSE19007 - CSE A

//Question 4 - BCast and Barrier Communication between N Nodes

/*
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include<iostream>


int main(int argc, char* argv[])
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    //Barrier to make the processes wait/block until it is called
    printf("[MPI process %d] Waiting on the barrier.\n", world_rank);
    MPI_Barrier(MPI_COMM_WORLD);
    printf("[MPI process %d] All Processes have waited on this barrier.\n", world_rank);

    int broadcast_root = 0;

    int buffer;
    if (world_rank == broadcast_root)
    {
        buffer = 19008;
        printf("[MPI process %d] I am the broadcast root, and I send the value of %d.\n", world_rank, buffer);
    }

    //BCast - To broadcast message from rank root to all the processes
    MPI_Bcast(&buffer, 1, MPI_INT, broadcast_root, MPI_COMM_WORLD);
    if (world_rank != broadcast_root)
    {
        printf("[MPI process %d] This is broadcast receiver, obtained the value of  %d.\n", world_rank, buffer);
    }
    MPI_Finalize();

    return EXIT_SUCCESS;;
}
*/

// LabAssignment-1.cpp 
// Program done by: B Sudharshan - CB.EN.U4CSE19008 - CSE A
// Athota Surya - CB.EN.U4CSE19007 - CSE A

//Question 5 - Average of an array using MPI_Scatter and MPI_Gather

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <assert.h>

float* create_rand_nums(int num_elements) {
    float* rand_nums = (float*)malloc(sizeof(float) * num_elements);
    assert(rand_nums != NULL);
    int i;
    for (i = 0; i < num_elements; i++) {
        rand_nums[i] = (rand() / (float)RAND_MAX);
    }
    return rand_nums;
}

float compute_avg(float* array, int num_elements) {
    float sum = 0.f;
    int i;
    for (i = 0; i < num_elements; i++) {
        sum += array[i];
    }
    return sum / num_elements;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: avg num_elements_per_proc\n");
        exit(1);
    }

    int num_elements_per_proc = atoi(argv[1]);

    srand(time(NULL));

    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);


    float* rand_nums = NULL;
    if (world_rank == 0) {
        rand_nums = create_rand_nums(num_elements_per_proc * world_size);
    }
    float* sub_rand_nums = (float*)malloc(sizeof(float) * num_elements_per_proc);
    assert(sub_rand_nums != NULL);


    MPI_Scatter(rand_nums, num_elements_per_proc, MPI_FLOAT, sub_rand_nums,
        num_elements_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);


    float sub_avg = compute_avg(sub_rand_nums, num_elements_per_proc);


    float* sub_avgs = NULL;
    if (world_rank == 0) {
        sub_avgs = (float*)malloc(sizeof(float) * world_size);
        assert(sub_avgs != NULL);
    }
    MPI_Gather(&sub_avg, 1, MPI_FLOAT, sub_avgs, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);


    if (world_rank == 0) {
        float avg = compute_avg(sub_avgs, world_size);
        printf("Avg of all elements is %f\n", avg);

        float original_data_avg =
            compute_avg(rand_nums, num_elements_per_proc * world_size);
        printf("Avg computed across original data is %f\n", original_data_avg);
    }


    if (world_rank == 0) {
        free(rand_nums);
        free(sub_avgs);
    }
    free(sub_rand_nums);

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
}
*/
#include <mpi.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    char msg1 = 'T1';
    char msg2 = 'T2';
    char msg4 = 'T4';
    char msg3 = 'T3';
    if (world_rank == 0)
    {
        //Receiveing the messages from Odd and Even Ranks/Nodes


        MPI_Recv(&msg1, 4, MPI_BYTE, 1, 'T1', MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("This is the master of rank %d among %d ,Received is: %s", world_rank, world_size, msg1);
        MPI_Recv(&msg2, 4, MPI_BYTE, 2, 'T2', MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("This is the master of rank %d among %d ,Received is: %s", world_rank, world_size, msg2);

    }
    //For Nodes with even rank
    else if (world_rank % 2 == 0)
    {
        //Sending the message TAG T4 to the master

        MPI_Send(&msg4, 4, MPI_BYTE, 0, 'T2', MPI_COMM_WORLD);
        printf("This is the slave of rank %d among %d ,Message sent is: %s", world_rank, world_size, msg4);
    }
    //For Nodes with Odd ranks
    else
    {
        //Sending the message TAG T3 to the master

        MPI_Send(&msg3, 4, MPI_BYTE, 0, 'T1', MPI_COMM_WORLD);
        printf("This is the slave of rank %d among %d ,Message sent is: %s", world_rank, world_size, msg3);
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}
