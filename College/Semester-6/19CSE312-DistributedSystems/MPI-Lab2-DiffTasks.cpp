// MPI-FirstAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<mpi.h>
#include<stdio.h>

int process0fn(int a,int b)
{
    printf("-----Sum of 2 Numbers------");
    printf("Sum is %d",a + b);
}
int process1fn(int a,int b)
{
    printf("-----Product of 2 Numbers------");
    printf("product is %d",a*b)
}

int main(inr argc,char* argv[])
{
    int my_id, root process, ierr, num_procs;
    MPI_Status status;

    ierr = MPI_Init(&argc, &argv);

    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int num1, num2;
    printf("Enter a number: ");
    scanf("%f", &num1);
    printf("Enter another number: ");
    scanf("%lf", &num2);

    if (my_id == 0)
    {
        printf("Process 0 Work Initiated");
        process0fn(num1,num2);
    }
        
    else
    {
        printf("Process 1 Work Initiated");
        process1fn(num1,num2);

    }

    ierr = MPI_Finalize();
    return 0;
}


