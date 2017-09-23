#include <stdio.h>
#include <mpi.h>

float Trap(float a, float b, int n, float h);

int main(int argc, char* argv[])
{
    int my_rank;             /* My process rank              */
    int p;                   /* The number of processes      */
    float a = 0.5;           /* Left endpoint                */
    float b = 2.0;           /* Right endpoint               */
    int n = 1024;            /* Number of trapezoids         */
    float h;                 /* Trapezoid base length        */
    float local_a;           /* Left endpoint my process     */
    float local_b;           /* Right endpoint my process    */
    int local_n;             /* Number of trapezoids         */
    float integral;          /* Integral over my interval    */
    float total = -1;        /* Total integral               */
    int source;              /* Process send integral        */
    int dest = 0;            /* All messages send to 0       */
    int tag = 0;
    int ierr;
    MPI_Status status;

    ierr = MPI_Init(&argc, &argv);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &p);

    h = (b - a) / n;            /* h is the same for all processes                  */
    local_n = n / p;            /* local_n is the trapezoids in each process        */
                                /* length of each process' interval is local_n * p  */
                            
    local_a = a + my_rank * local_n * h;            /* process 0 does not calculate */
    local_b = local_a + local_n * h;
    integral = Trap(local_a, local_b, local_n, h);

    // add up the integrals by each process
    if (my_rank == 0)
    {
        total = integral;
        for (source = 1; source < p; source++)
        {
            ierr = MPI_Recv(&integral, 1, MPI_FLOAT, source, tag, MPI_COMM_WORLD, &status);
            printf("PE %d <- %d, %f\n", my_rank, source, integral);
            total += integral;
        }
    }
    else
    {
        printf("PE %d -> %d, %f\n", my_rank, dest, integral);
        MPI_Send(&integral, 1, MPI_FLOAT, dest, tag, MPI_COMM_WORLD);
    }

    // print the result;
    if (my_rank == 0)
    {
        printf("With n = %d trapezoids, our estimate\nof the interal from %f to %f = %f\n",
                n, a, b, total);
    }

    ierr = MPI_Finalize();
    return ierr;
}