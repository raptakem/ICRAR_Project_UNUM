#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  A single example of using Heron's Formula for the areas of triangles to show deviations
  in Area when rounding is considered.
*/

using namespace std;

long double Area_ld(){
  /*
    Using 96 Bit Floats (long double)
  */
    long double ULP = pow(2.0,-52); //1 ULP (Unit in the Last Place) of a double precision float is 2^-52

    //Setting up the dimensions of our incredibly short triangle
    long double a = 7.0;
    long double b = 7.0/2.0 + 3 * ULP;
    long double c = 7.0/2.0 + 3 * ULP;

    //Using Heron's Formula for Triangles
    long double s = (a + b + c)/2;
    long double A = sqrt((s*(s-a)*(s-b)*(s-b)));

    return A;
}

double Area_d(){
  /*
    Using 64 Bit Floats (double)
  */
    double ULP = pow(2.0,-52); //1 ULP (Unit in the Last Place) of a double precision float is 2^-52

    //Setting up the dimensions of our incredibly short triangle
    double a = 7.0;
    double b = 7.0/2.0 + 3 * ULP;
    double c = 7.0/2.0 + 3 * ULP;

    //Using Heron's Formula for Triangles
    double s = (a + b + c)/2;
    double A = sqrt((s*(s-a)*(s-b)*(s-b)));

    return A;
}

void Error_Analysis(){

    double A_ld = Area_ld();
    double A_d = (long double) Area_d();

    //Performing Error Analysis between the 64bit and 96bit calculated values
    double Abs_error = fabs(A_ld - A_d);
    double Percent_error = (Abs_error / A_ld) * 100;

    //Returning Error Analysis to Console
    printf("The Absolute Error between the two Calculations is: %.10e \n", Abs_error);
    printf("The Percentage Error between the two Calculations is: %.10lf %% \n", Percent_error);
}

int main(){

  double A_64 = Area_d();
  double A_96 = (double) Area_ld(); //Casting a 96 bit float to 64 bit so it can be output in the console

  //Reporting the two Areas
  printf("The Area of the Triangle (Calculated with 64 bit Floats) is: %.10e \n", A_64);
  printf("The Area of the Triangle (Calculated with 96 bit Floats) is: %.10e \n", A_96);

  //Report the Differences
  Error_Analysis();

  return 0;
}
