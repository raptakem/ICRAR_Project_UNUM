/*
The purpose of this code is to illustrate the issues arising from rounding errors in the
IEEE floating point approach in scientific computing. This is done by using a simple chaotic
system; the discrete Logistic map with a 'chaotic' r parameter.
*/

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

//r values greater than 3.56995 cause the map to exhibit chaotic behaviour
long double r_96 = 3.6;
double r_64 = 3.6;
float r_32 = 3.6;

/*
Three similar methods for performing the iteration x_n+1 = r * x_n * (1 - x_n) for each of the floating point types
*/

long double iterate_96(long double x_96){
  long double xnext_96 = r_96 * x_96 * (1 - x_96);
  return xnext_96;
}

double iterate_64(double x_64){
  double xnext_64 = r_64 * x_64 * (1 - x_64);
  return xnext_64;
}

float iterate_32(float x_32){
  float xnext_32 = r_32 * x_32 * (1 - x_32);
  return xnext_32;
}

int main(){

  ofstream output; //output file stream
  output.open("LogisticData.dat"); //output file name

  long double x_96 = 0.5;
  double x_64 = 0.5;
  float x_32 = 0.5;

for(int i=0 ; i <= 1000 ; i++){

  double x_96_display = (double) x_96;
  //reporting 96-bit floats causes errors unless we convert them to 64-bit floats first

  //report to the console
  printf("%i-th iteration \n", i);
  printf("x96 is %11.10f \n", x_96_display);
  printf("x64 is %11.10f \n", x_64);
  printf("x32 is %11.10f \n \n", x_32);


  //write in the .dat file
  output << i << " ";
  output << x_96_display << " ";
  output << x_64 << " ";
  output << x_32 << "\n";

  //iterate to the next step
  x_96 = iterate_96(x_96);
  x_64 = iterate_64(x_64);
  x_32 = iterate_32(x_32);
}
  return 0;
}
