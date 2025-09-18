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

bool findinitialguesses (const vector<double>& coeffs,double & x1, double & x2,double step = 0.1 ){
    double R = maxrootestimate ( coeffs );
    double prevX = -R ;
    double prevF = f ( coeffs ,prevX);
    for (double x=-R+step){
        double currF = f ( coeffs,x);
        if ( prevF*currF<0){
            x1 = prevX;
            x2=x;
            return true ;
        }
        prevX  = x;
        prevF = currF;
    }
    return false;
}
void  falsePosition (const vector<double>& coeffs, double x1, double x2, double tolerance, int maxIterations){
    double fx1 = f(coeffs, x1);
    double fx2 = f(coeffs, x2);

    if (fx1 * fx2 > 0){
        cout<< "Error: f (x1) and f (x2) must have opposite singns.\n";
        return;
    }
    double x0, fx0, prevx0, relativeError;
    int iteration =0;
    bool firstIteration = true;
    cout << "\nIteration Table:\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "Iter |      x1      |      x2      |      x0      |     f(x0)    | Relative Error\n";
    cout << "-------------------------------------------------------------------------------\n";

}
































































int main(){
    int degree;
}
