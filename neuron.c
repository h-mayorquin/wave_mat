#include<stdio.h>
#include<stdlib.h>
//#include<mpi.h>

int main(){
  /* Programm variables */
  int i;
  FILE *fp;

  // Let's open a file to save the data
  fp = fopen("results.dat", "w");
  if (fp == NULL) {
    printf("I couldn't open results.dat for writing.\n");
    exit(0);
  }
   
  /* First we need the carachteristics of the neuron */
  float tau = 20; // ms
  float Vth = 0; // mV
  float Vre = -70; // mV
  float Ve = 10; // mV

  /* Now the parameters of the simulation */

  float T = 100; // ms
  float dt = 0.1; // ms
  int Nt = T / dt; // Total time of the simulation

  // Now we initialize the simulation
  float V = -50;

  
  for(i=0; i<Nt; ++i){
    // Move the differential equation
    V = V + (Ve - V) * (dt / tau);
    // Check threshold 
    if(V >= Vth){
      V = Vre; 
    }
    // Save the data 
    fprintf(fp, "%f \n", V); // Save the data 
  }


  return 0;
}
