#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
  int ierr, procid, numprocs;

  // init
  ierr = MPI_Init(&argc, &argv);
  
  // find out process rank
  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &procid);

  // No. of Process
  ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  // let each process print something;
  printf("Hello world from Process #%d out of %d!\n", procid, numprocs);
  
  // shut down MPI
  ierr = MPI_Finalize();

  return ierr;
}
