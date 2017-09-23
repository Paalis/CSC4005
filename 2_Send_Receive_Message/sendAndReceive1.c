// MPI_Send(buf, count, type, dest, tag, comm)

// Arg          I/O         Desc
// buf          In          starting address of send buffer
// count        In          number of elements in the send buffer
// type         In          MPI_Datatype of each send buffer element
// dest         In          node rank id to send the buffer to
// tag          In          message tag
// comm         In          communicator

// MPI_Send transits 'count' elements in 'buf' all of type 'type' to node 'dest' with label 'tag'

// MPI_Recv(buf, count, type, src, tag, comm, status)

// Arg          I/O         Desc
// buf          In          starting address of receive buffer
// count        In          number of elements in receive buffer
// type         In          MPI_Datatype of each buffer element
// src          In          node rank id to receive the buffer from
// tag          In          receive tag
// comm         In          communicator
// status       Out         status object

/*
    If you see this when doing "mpirun":

        PMIx has detected a temporary directory name that results
        in a path that is too long for the Unix domain socket:

            Temp dir: /var/folders/wh/ss8jdkr96yqdlvqxw1l03c500000gn/T/openmpi-sessions-501@FluoriteMacBook_0/33919

        Try setting your TMPDIR environmental variable to point to
        something shorter in length
    
    You can change the temp dir to a shorter directory by executing this line in the terminal:
    
        export TEMPDIR=<a temporary dir>

    where <a temporary dir> can be any directory, such as /tmp
*/

#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
    int ierr, procid, numprocs;

    ierr = MPI_Init(&argc, &argv);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &procid);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    if (numprocs != 2)
    {
        printf("ERROR: Number of processes is nor 2!\n");
        return MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (procid == 0)
    {
        // process 0 will send the number 3.14 to process 1
        double pi = 3.14;
        MPI_Send(&pi, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        printf("ProcID %d sent value %lf to Procid 1.\n", procid, pi);
    }
    else
    {
        // process 1 will wait to receive a double from procid 0;
        double value;
        MPI_Status status;
        ierr = MPI_Recv(&value, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
        if (ierr == MPI_SUCCESS)
        {
            printf("ProcID %d received value %lf.\n", procid, value);
        }
        else{
            printf("ProcID %d did not successfully receive a value!\n", procid);
        }
    }
    ierr = MPI_Finalize();
    return ierr;
}
