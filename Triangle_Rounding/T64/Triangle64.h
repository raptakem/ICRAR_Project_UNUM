#ifndef TRIANGLE64_H
#define TRIANGLE64_H

/*
  The Triangle_64 class creates a triangle using 64 bit floating points for all
  of its variables in order to show the issues arising from rounding errors in the
  IEEE floating points from the percentage differences in area between the 'exact same'
  triangles constructed with 64 bit and 96 bit floats.
*/

class Triangle64{

public:

  Triangle64(double Base, int N_ulps); //Initializes dimensions and calls getArea

  double getArea(); //Returns the area of the triangle

private:

  void setArea(); //Calculates the area of the triangle (only called in Constructor)

  //Variables reflecting the properties of the triangle
  double Base;
  double Diagonals;
  int N_ulps;
  double s; //From Heron's Formula (half of the perimeter)
  double Area;
  double ULP; //ULP size of 64 bit Floats i.e. 2^-52
};

#endif
