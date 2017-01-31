#ifndef TRIANGLE96_H
#define TRIANGLE96_H

/*
  The Triangle_96 class creates a triangle using 96 bit floating points for all
  of its variables in order to show the issues arising from rounding errors in the
  IEEE floating points from the percentage differences in area between the 'exact same'
  triangles constructed with 64 bit and 96 bit floats.
*/

class Triangle96{

public:

  Triangle96(long double Base, int N_ulps); //Initializes dimensions and calls getArea

  long double getArea(); //Returns the area of the triangle

private:

  void setArea(); //Calculates the area of the triangle (only called in Constructor)

  //Variables reflecting the properties of the triangle
  long double Base;
  long double Diagonals;
  int N_ulps;
  long double s; //From Heron's Formula (half of the perimeter)
  long double Area;
  long double ULP; //ULP size of 64 bit Floats i.e. 2^-52
};

#endif
