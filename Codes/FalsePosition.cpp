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
