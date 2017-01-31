#include "Triangle64.h"
#include <math.h>
#include <cmath>
#include <stdio.h>

//Const. - set Dims and calculate Area
Triangle64::Triangle64(double Base, int N_ulps){

  ULP = pow(2.0,-52); //ULP size for 64 bit Floats

  this->Base = Base;
  this->N_ulps = N_ulps;
  Diagonals = Base/2 + ((double)N_ulps) * ULP;

  setArea();
}

//Calcualates Area using Heron's Formula
void Triangle64::setArea(){
  s = (Base + 2 * Diagonals)/2;
  Area = sqrt((s*(s-Base)*(s-Diagonals)*(s-Diagonals)));
}

//Returns Area
double Triangle64::getArea(){
  return Area;
}
