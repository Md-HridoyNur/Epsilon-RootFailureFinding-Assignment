#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

using namespace std;

double f(const vector<double>& coeffs,double x){
    int n = coeffs.size()-1;
    for (int i=0;i<=n;i++){
        result += coeffs[i]*pow(x,n-1);
    }
    return result ;
}

double maxrootestimate ( const vector<double>& coeffs){
    int n = coeffs.size()-1;
    if (n<2) return 1.0;
    double a_n = coeffs[0];
    double a_n1 = coeffs[1];
    double a_n2 = coeffs[2];
    double discrim = ( a_n1 / a_n)*(a_n1/a_n)-2*(a_n2/a_n);
    if ( discrim <0 ) discrim = 0;
    return sqrt ( discrim);
}


