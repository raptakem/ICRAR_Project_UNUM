//Include Dependencies from C++
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Include Dependencies within Project
#include "T64/Triangle64.cpp"
#include "T96/Triangle96.cpp"

/*
  A Looped example of using Heron's Formula for the areas of multiple triangles to show deviations
  in Area when rounding is considered and considering them as a function of the number of ULP by first
  saving the data to a .dat file
*/

using namespace std;

double Error_Analysis(double A_64, long double A_96){

    double errors[2];

    //Performing Error Analysis between the 64bit and 96bit calculated values
    double Abs_error = fabs(A_96 - A_64);
    double Percent_error = (Abs_error / A_96) * 100;

    //Returning Error Analysis to Console
    printf("The Absolute Error between the two Calculations is: %.10e \n", Abs_error);
    printf("The Percentage Error between the two Calculations is: %.10lf %% \n\n\n", Percent_error);

    return Percent_error;
}

int main(){

  ofstream output;
  output.open("TriangleData.dat");

  double b = 7.0;

  for(int i = 1; i <= 10000; i++){
    {
      /*
      Curly Brackets used to destroy the object after it is used to free up the memory allocated to it
      */

    //Create the Triangles by initializing the objects
    Triangle64 T64(b,i);
    Triangle96 T96((long double) b,i);

    double A_64 = T64.getArea();
    double A_96 = (double) T96.getArea();

    printf("The Area of the 64bit Triangle with %i ULP's added is: %.10e \n", i, A_64);
    printf("The Area of the 96bit Triangle with %i ULP's added is: %.10e \n \n", i, A_96);

    output << i << " ";
    output << Error_Analysis(A_64,A_96);
    output << "\n";

    }
  }
  output.close();
  return 0;
}
