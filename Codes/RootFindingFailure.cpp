#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;


constexpr int MAXIT = 200;
constexpr double TOL = 1e-10;

double f_cuberoot(double x) { return cbrt(x); }
ouble df_cuberoot(double x) {
    
