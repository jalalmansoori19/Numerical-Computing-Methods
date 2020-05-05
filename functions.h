#ifndef		FUNCTIONS_H
#define		FUNCTIONS_H

// functions declarations

void display();
void display2();
// For Newton Raphson Method
double getFuncValue(double xi);
double getFuncDerivValue(double xi);
double getNewValue(double xi);
void newtonRaphson(double xi);
void showInterval();
bool checkValue(double xi);
float getNuminfourDecimal(float var);

// For Secant Method
void secantMethod(double xi);
double getNewSecantValue(double xi, double prev);

// For Bisection Method
double getCValue(double a, double b);
void bisectionMethod();

// For Regular False method
double getCFalsiValue(double a, double b);
void regularFalsiMethod();

// For Fixed Point Iteration Method
void fixedPointIter(double xi);
double getGofX(double xi);

// For Polynomial Function
void Polynomial(int degree);
double getPolyFuncValue(double xi, int coefficients[], int power[], int size);
//For Bisection
void bisectionForPoly(int coefficients[], int power[], int size);
//For Regular Falsi
void regularFalsiForPoly(int coefficients[], int power[], int size);
double getCFalsiValueForPoly(double a, double b, int coefficients[], int power[], int size);

//For Fixed Iteration Method
double getGofXForPoly(double x, int coefficients[], int power[], int size);
void fixedPointIter(double xi, int coefficients[], int power[], int size);

// For Newton Raphson Method

double getPolyFuncDerivValue(double xi, int coefficients[], int power[], int size);
void newtonRaphsonForPoly(double xi, int coefficients[], int power[], int size);
double getNewValueForPoly(double xi, int coefficients[], int power[], int size);

//For Secant Method
void secantMethodForPoly(double xi, int coefficients[], int power[], int size);
double getNewSecantValueForPoly(double xi, int coefficients[], int power[], int size, double prev);

void displayKey();

#endif
