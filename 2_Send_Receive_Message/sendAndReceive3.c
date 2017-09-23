#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
    int ierr, procid, numprocs;

    ierr = MPI_Init(&argc, &argv);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &procid);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    // send -procid to procid 0
    double val = (-1) * procid;
    MPI_Send(&val, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    printf("ProcID %d sent value %lf to Procid 0.\n", procid, val);

    // procid 0 receive 'numpros' values.
    if (procid == 0)
    {
        double val, sum = 0;
        MPI_Status status;

        for (int i = 0; i != numprocs; i++)
        {
            ierr = MPI_Recv(&val, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
            if (ierr == MPI_SUCCESS)
            {
                printf("ProcID %d received value %lf\n", procid, val);
                sum += val;
            }
            else
            {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            printf("The total is %lf.\n", sum);
        }
        ierr = MPI_Finalize();
        return ierr;
    }

    ierr = MPI_Finalize();
    return ierr;
}