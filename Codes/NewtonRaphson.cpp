#include <istream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

double f(const vector<double>& coeffs, double x) {
    int n = coeffs.size() - 1;
    double result = 0.0;
    for (int i=0; i<=n; i++) {
        result += coeffs[i] * pow(x, n - i);
    }
    return result;
}

double df(const vector<double>& coeffs, double x) {
    int n = coeffs.size() - 1;
    double result = 0.0;
    for (int i=0; i<n; i++) {
        result += (n - i) * coeffs[i] * pow(x, n - i - 1);
    }
    return result;
}

Newton-Raphson method
void newtonRaphson(const vector<double>& coeffs, double x0, double tolerance, int maxIterations) {
    double x1, fx, dfx, relativeError;
    int iteration = 0;
    bool converged = false;

   
