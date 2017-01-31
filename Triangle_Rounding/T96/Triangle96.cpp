#include "Triangle96.h"
#include <math.h>
#include <cmath>
#include <stdio.h>

//Const. - set Dims and calculate Area
Triangle96::Triangle96(long double Base, int N_ulps){

  ULP = pow(2.0,-52); //ULP size for 64 bit Floats

  this->Base = Base;
  this->N_ulps = N_ulps;
  Diagonals = Base/2 + ((long double)N_ulps) * ULP;

  setArea();
}

//Calcualates Area using Heron's Formula
void Triangle96::setArea(){
  s = (Base + 2 * Diagonals)/2;
  Area = sqrt((s*(s-Base)*(s-Diagonals)*(s-Diagonals)));
}

//Returns Area
long double Triangle96::getArea(){
  return Area;
}
