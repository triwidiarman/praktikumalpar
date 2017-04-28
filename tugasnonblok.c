#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
  // Inisiasi Environment Awal
  MPI_Init(NULL, NULL);
  
  //Mencari Rank dan Size 
  int a;
  MPI_Comm_rank(MPI_COMM_WORLD,&a);
  int b;
  MPI_Comm_size(MPI_COMM_WORLD,&b);
  MPI_Request z;
  //Menggunakan 2 Processor
  if (b < 2) {
    fprintf(stderr, "Ukuran Global harus lebih besar dari 1 untuk  %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int no;
  
  if (a == 0) {
    no= -1;
    MPI_Isend(&no, 1, MPI_INT, 1,0,MPI_COMM_WORLD,&minta);
  } else if (world_rank == 1) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", number);
  }
  
  MPI_Finalize();	
}