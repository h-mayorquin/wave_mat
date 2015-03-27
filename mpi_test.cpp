/* C Example */
#include <mpi.h>
#include <iostream>

using namespace std;
 
int main (int argc, char* argv[])
{ 
 int rank, size;
 
  MPI_Init (&argc, &argv);      /* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);        /* get current process id */
  MPI_Comm_size (MPI_COMM_WORLD, &size);        /* get number of processes */
  cout << "Hello world from process " << rank << size;
  cout << "Finish line " << endl;
  MPI_Finalize();
  return 0;
}
