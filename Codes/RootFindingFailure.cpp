#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;

constexpr int MAXIT = 200;
constexpr double TOL = 1e-10;

double f_cuberoot(double x) { return cbrt(x); }
ouble df_cuberoot(double x) {
    if (x == 0.0) return 0.0;
    double t = cbrt(x);
    return (1.0 / 3.0) / (t * t);
}

double f_repeat2(double x) { double t = x - 1.0; return t * t; }
double df_repeat2(double x) { return 2.0 * (x - 1.0); }

double f_x3(double x) { return x * x * x; }
double df_x3(double x) { return 3.0 * x * x; }

double f_quad(double x) { return x*x - 2.0; }
double df_quad(double x) { return 2.0 * x; }

int pow_n = 50;
double f_pown(double x) { return pow(x, pow_n) - 1.0; }

