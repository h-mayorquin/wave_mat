#include<stdio.h>
#include<stdlib.h>
//#include<mpi.h>

#include "function_network.h"


int main(){
  /* Programm variables */
  int i, j, t, k;
  FILE *fp;

  // Let's open a file to save the data
  fp = fopen("network_results.dat", "w");
  if (fp == NULL) {
    printf("I couldn't open results.dat for writing.\n");
    exit(0);
  }

  /* Network parameters */
  int Nx = 30;
  int Ny = 30;
  float neural_network[Nx][Ny];
  float seed = 23;

  /* Interaction parameters */
  float alpha = 15.0;
  float beta = 5.0; 
  float r_alpha = 5;
  float r_beta = 15; // r_alpha + r_beta should be less than Nx * Ny
   
  /* First we need the carachteristics of the neuron */
  float tau = 20; // ms
  float Vth = 0; // mV
  float Vre = -70; // mV
  float Ve = 10.0; // mV
  int range = (int) (Vth - Vre); // mV

  /* Now the parameters of the simulation */

  float T = 100; // ms
  float dt = 0.1; // ms
  int Nt = T / dt; // Total time of the simulation

  // Now we initialize the simulation
  float V = -50;

  initialize_network(Nx, Ny, neural_network, Vth, Vre, seed);
  print_network(Nx, Ny, neural_network);
  
  
  for(t=0; t<Nt; ++t){
    for(i=0; i<Nx; ++i){
      for(j=0; j<Ny; ++j){
	// Evolve the network 
	neural_network[i][j] += (Ve - V) * (dt / tau);

	// Watch for spikes 
	if(neural_network[i][j] >= Vth){
	  neural_network[i][j] = Vre;

	  // Now add the interaction / Spikes 

	  // First the push 
	  for(k=1; k<r_alpha; ++k){

	    // Create the periodic indexes
	    int  x_index_1 = (int) (i + k) % Nx;
	    int x_index_2 = (int) (i - k) % Nx;
	    int y_index_1 = (int) (j + k) % Ny;
	    int y_index_2 = (int) (j - k) % Ny;

	    // Do the updates 
	    neural_network[x_index_1][j] += alpha;
	    neural_network[x_index_2][j] += alpha;
	    neural_network[i][y_index_1] += alpha;
	    neural_network[i][y_index_2] += alpha;

	  }

	  // Now the inhibition 
	  for(k=r_alpha; k<r_beta; ++k){

	    // Create the periodic indexes
	    int  x_index_1 = (int) (i + k) % Nx;
	    int x_index_2 = (int) (i - k) % Nx;
	    int y_index_1 = (int) (j + k) % Ny;
	    int y_index_2 = (int) (j - k) % Ny;
	    
	    // Do the updates 
	    neural_network[x_index_1][j] -= beta;
	    neural_network[x_index_2][j] -= beta;
	    neural_network[i][y_index_1] -= beta;
	    neural_network[i][y_index_2] -= beta;
	  }

	}


	// Save the data 
	fprintf(fp, "%f,", neural_network[i][j]); // Save the data
      }
      fprintf(fp, "\n"); // Skip at the end of the column 
    }
    fprintf(fp, "\n");  // Space between data-matrixes 

  }

  return 0;

}
