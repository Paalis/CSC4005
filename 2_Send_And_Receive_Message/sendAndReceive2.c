#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
    int ierr, procid, numprocs;

    ierr = MPI_Init(&argc, &argv);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &procid);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    if (numprocs %2 != 0)
    {
        printf("ERROR: Number of processes is not even!\n");
        return MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (procid %2 == 0)
    {
        // even procid i will send the number 3.14+i to procid i+1
        double val = 3.14 + procid;
        MPI_Send(&val, 1, MPI_DOUBLE, procid+1, 0, MPI_COMM_WORLD);
        printf("ProcID %d sent value %lf to procid %d.\n", procid, val, procid+1);
    }
    else
    {
        // odd procid will wait to receive a value from any procid
        double val;
        MPI_Status status;
        ierr = MPI_Recv(&val, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        if (ierr == MPI_SUCCESS)
        {
            printf("ProcID %d received value %lf.\n", procid, val);
        }
        else
        {
            printf("ProcID %d did not successfully receive a value!", procid);
        }
    }

    ierr = MPI_Finalize();
    return ierr;
    
}