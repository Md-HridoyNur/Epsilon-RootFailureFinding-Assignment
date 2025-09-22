#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Maximum number of iterations and tolerance for convergence
constexpr int MAXIT = 200;
constexpr double TOL = 1e-10;

// ---------- Test Functions and Their Derivatives ----------
// Function: f(x) = cbrt (x) (cube root)
// Used to demonstrate divergence of Newton's method
double f_cuberoot(double x) { return cbrt(x); }

// Derivative of cbrt(x) = 1 / (3 * cbrt(x)^2)
double df_cuberoot(double x) {
    if (x == 0.0) return 0.0;
    double t = cbrt(x);
    return (1.0 / 3.0) / (t * t);
}
// Function: f(x) = (x - 1)^2 (repeated root at x=1)
double f_repeat2(double x) { double t = x - 1.0; return t * t; }
double df_repeat2(double x) { return 2.0 * (x - 1.0); }

// Function: f(x) = x^3
double f_x3(double x) { return x * x * x; }
double df_x3(double x) { return 3.0 * x * x; }
// Function: f(x) = x^ 2 - 2 (root = sqrt(2))
double f_quad(double x) { return x*x - 2.0; }
double df_quad(double x) { return 2.0 * x; }
// Function: f(x) = x^n - 1 (slow convergence when n is large)
int pow_n = 50;
double f_pown(double x) { return pow(x, pow_n) - 1.0; }

// -------- Newton-Raphson Method --------
void newton_method(double (*f)(double), double (*df)(double),
                  double x0, int maxit, double tol, const string& tag) { 
      cout << "----- Newton-Raphson: " << tag << " | x0 = " << fixed << setprecision(6) << x0 << " -----\n";
        cout << setw(6) << "Iter" << setw(12) << "x0" << setw(12) << "f(x0)" << setw(12) << "f'(x0)"
          << setw(12) << "x1" << setw(14) << "RelError(%)\n";

double x = x0;
for (int k = 1; k <= maxit; ++k) {
  double fx = f(x);
  double dfx = df(x);
  
    // Handle derivative ~ 0 (Newton fails)
  if (fabs(dfx) < 1e-14) {
    cout << setw(6) << k << setw(12) << x << setw(12) << fx << setw(12) << 0
      << setw(12) << x << setw(14) << "derivative~0" << "\n";
   return;
 }
// Newton update formula: x1 = x0 - f(x0)/f'(x0)
double dx = fx / dfx;
double x1 = x - dx;
double relErr = (k==1)? 100.0 : fabs((x1 - x)/x1)*100;

cout << setw(6) << k << setw(12) << x << setw(12) << fx << setw(12) << dfx
  << setw(12) << x1 << setw(14) << relErr << "\n";

    // Check for convergence
    if (fabs(dx) < tol) {
   cout << "Converged to x = " << x1 << " after " << k << " iterations, f(x)= " << f(x1) << "\n";
    return;
  }
  x = x1;
 }
 cout << "Max iterations reached; last x = " << x << ", f(x) = " << f(x) << "\n";
}

// ---------- False Position (Regular Falsi) ----------
void false_position(double (*f)(double), double x1, double x2, int maxit, double tol, const string& tag) {
cout << "----- False Position: " << tag << " | bracket = [" << x1 << ", " << x2 << "] -----\n";
double f1 = f(x1), f2 = f(x2);

// Root must be bracketed (sign change required)
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

    // Check for convergence
    if (fabs(f0)<tol || relErr<tol) {
      cout << "Converged to x0 = " << x0 << " after " << k << " iterations, f(x0)= " << f0 << "\n";
     return;
  }

    // Update interval
if (f1*f0<0) { x2 = x0; f2 = f0; }
 else { x1 = x0; f1 = f0; }

  prevX0 = x0;
  }
  cout << "Max iterations reached; last x0 = " << x0 << ", f(x0) = " << f0 << "\n";
}

// ---------- Illinois Method (Modified False Position) ----------
void false_position_illinois(double (*f)(double), double x1, double x2, int maxit, double tol, const string& tag) {
cout << "----- False Position (Illinois): " << tag << " | bracket = [" << x1 << ", " << x2 << "] -----\n";
double f1 = f(x1), f2 = f(x2);

    // Root must be bracketed
if (f1*f2>=0) { cout << "Endpoints must have opposite signs.\n"; return; }

cout << setw(6) << "Iter" << setw(12) << "x1" << setw(12) << "x2"
  << setw(12) << "x0" << setw(12) << "f(x0)" << setw(14) << "RelError(%)\n";

double x0, f0, prevX0=0;
  int lastUpdated = 0; // track which endpoint was updated last
    for(int k=1; k<=maxit; ++k) {
        x0 = x2 - f2*(x2 - x1)/(f2 - f1);
        f0 = f(x0);
        double relErr = (k==1)? 100.0 : fabs((x0 - prevX0)/x0)*100;

              cout << setw(6) << k << setw(12) << x1 << setw(12) << x2
             << setw(12) << x0 << setw(12) << f0 << setw(14) << relErr << "\n";
        // Convergence check
        if (fabs(f0)<tol || relErr<tol) {
            cout << "Converged to x0 = " << x0 << " after " << k << " iterations, f(x0)= " << f0 << "\n";
            return;     
        }
 // Illinois modification: reduce the stagnant endpoint’s function value
        if(f1*f0<0) {
            x2 = x0; f2 = f0;
            if(lastUpdated == 1) f1 *= 0.5;
            lastUpdated = 2;
        } else {
            x1 = x0; f1 = f0;
            if(lastUpdated == 1) f2 *= 0.5;
            lastUpdated = 1;
        }

        prevX0 = x0;
    }
    cout<<"Max iterations reached; last x0 = " << x0 << ", f(x0) = " << f0 << "\n";
}
// ---------- Main Driver ----------
int main() {
    cout << "\nROOT-FINDING FAILURE DEMONSTRATIONS (C++) \n\n";
    // Demonstrations with Newton's method
    newton_method(f_cuberoot, df_cuberoot, 0.1, 20, 1e-12, "f(x)=cuberoot(x) -> divergent");
    cout << "\n";
    newton_method(f_repeat2, df_repeat2, 2.0, 40, 1e-12, "f(x)=(x-1)^2 -> repeated root");
    cout << "\n";
  newton_method(f_x3, df_x3, 0.0, 10, 1e-12, "f(x)=x^3 with x0=0 (derivative=0)");
    cout << "\n";
    newton_method(f_quad, df_quad, 1.0, 20, 1e-12, "f(x)=x^2-2 (good convergence)");

    cout << "\n--------------------------------------------\n\n";
 // Demonstrations with False Position and Illinois methods
    pow_n = 50;
    false_position(f_pown, 0.0, 2.0, 200, 1e-12, "f(x)=x^50-1 slow");
    cout << "\n";
    false_position_illinois(f_pown, 0.0, 2.0, 200, 1e-12, "f(x)=x^50-1 Illinois");
   // Summary
    cout << "\nSummary:\n";
    cout << " - Newton diverges for cbrt(x) because x_{n+1}=-2x_n.\n";
    cout << " - Newton slow for repeated roots.\n";
    cout << " - False Position may move one endpoint slowly; Illinois improves convergence.\n";

    return 0;
  }
