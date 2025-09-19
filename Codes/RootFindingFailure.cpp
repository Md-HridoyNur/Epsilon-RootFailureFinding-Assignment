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

void newton_method(double (*f)(double), double (*df)(double),
                  double x0, int maxit, double tol, const string& tag) { 
      cout << "----- Newton-Raphson: " << tag << " | x0 = " << fixed << setprecision(6) << x0 << " -----\n";
        cout << setw(6) << "Iter" << setw(12) << "x0" << setw(12) << "f(x0)" << setw(12) << "f'(x0)"
          << setw(12) << "x1" << setw(14) << "RelError(%)\n";

double x = x0;
for (int k = 1; k <= maxit; ++k) {
  double fx = f(x);
  double dfx = df(x);
  if (fabs(dfx) < 1e-14) {
    cout << setw(6) << k << setw(12) << x << setw(12) << fx << setw(12) << 0
      << setw(12) << x << setw(14) << "derivative~0" << "\n";
   return;
 }
double dx = fx / dfx;
double x1 = x - dx;
double relErr = (k==1)? 100.0 : fabs((x1 - x)/x1)*100;

cout << setw(6) << k << setw(12) << x << setw(12) << fx << setw(12) << dfx
  << setw(12) << x1 << setw(14) << relErr << "\n";

  if (fabs(dx) < tol) {
   cout << "Converged to x = " << x1 << " after " << k << " iterations, f(x)= " << f(x1) << "\n";
    return;
  }
  x = x1;
 }
 cout << "Max iterations reached; last x = " << x << ", f(x) = " << f(x) << "\n";
}

void false_position(double (*f)(double), double x1, double x2, int maxit, double tol, const string& tag) {
cout << "----- False Position: " << tag << " | bracket = [" << x1 << ", " << x2 << "] -----\n";
double f1 = f(x1), f2 = f(x2);
if (f1*f2>=0) { cout << "Endpoints must have opposite signs.\n"; return; }

cout << setw(6) << "Iter" << setw(12) << "x1" << setw(12) << "x2"
  << setw(12) << "x0" << setw(12) << "f(x0)" << setw(14) << "RelError(%)\n";

double x0, f0, prevX0=0;
for(int k=1; k<=maxit; ++k) {
   x0 = x2 - f2*(x2 - x1)/(f2 - f1);
   f0 = f(x0);
   double relErr = (k==1)? 100.0 : fabs((x0 - prevX0)/x0)*100;

   cout << setw(6) << k << setw(12) << x1 << setw(12) << x2
      << setw(12) << x0 << setw(12) << f0 << setw(14) << relErr << "\n";

   if (fabs(f0)<tol || relErr<tol) {
      cout << "Converged to x0 = " << x0 << " after " << k << " iterations, f(x0)= " << f0 << "\n";
     return;
  }

if (f1*f0<0) { x2 = x0; f2 = f0; }
 else { x1 = x0; f1 = f0; }

prevX0 = x0;
}
cout << "Max iterations reached; last x0 = " << x0 << ", f(x0) = " << f0 << "\n";
}

oid false_position_illinois(double (*f)(double), double x1, double x2, int maxit, double tol, const string& tag) {








       

    




        
