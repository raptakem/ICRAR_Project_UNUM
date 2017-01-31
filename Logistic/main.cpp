/*
The purpose of this code is to illustrate the issues arising from rounding errors in the
IEEE floating point approach in scientific computing. This is done by using a simple chaotic
system; the discrete Logistic map with a 'chaotic' r parameter.
*/

#include <iostream>
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

  long double x_96 = 0.5;
  double x_64 = 0.5;
  float x_32 = 0.5;

for(int i=0 ; i < 1000 ; i++){

  double x_96_display = (double) x_96;

  printf("x96 is %f \n", x_96_display);
  printf("x64 is %f \n", x_64);
  printf("x32 is %f \n \n", x_32);

  x_96 = iterate_96(x_96);
  x_64 = iterate_64(x_64);
  x_32 = iterate_32(x_32);
}
  return 0;
}
