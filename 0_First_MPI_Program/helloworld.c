#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
  int procid, numprocs;

  // init
  MPI_Init(&argc, &argv);
  
  // find out process rank
  MPI_Comm_rank(MPI_COMM_WORLD, &procid);

  // No. of Process
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  // let each process print something;
  printf("Hello world from Process #%d out of %d!\n", procid, numprocs);
  
  // shut down MPI
  MPI_Finalize();

  return 0;
}
