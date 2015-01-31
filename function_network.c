#include <stdio.h>
#include<stdlib.h>

#include "function_network.h"


void print_network(int  Nx, int Ny, float neural_network[Nx][Ny]){

  int i, j;
    
  /* Print the values */
  for(i=0; i<Nx; ++i){
    for(j=0; j<Ny; ++j){
      printf("%f, ", neural_network[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
}

void initialize_network(int Nx, int Ny, float neural_network[Nx][Ny], float Vth, float Vre, float seed){

  int i, j; 
  int range = (int) (Vth - Vre); // mV

  srand(seed);
  
  /*Initialize the network */
  for(i=0; i<Nx; ++i){
    for(j=0; j<Ny; ++j){
      neural_network[i][j] = rand() % range + Vre;
    }
  }


}


