#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

using namespace std;

double f(const vector<double>& coeffs,double x){
    int n = coeffs.size()-1;
    double result = 0.0;
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
    for (double x= -R + step; x<= R; x+= step){
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
    
    do {
       fx1= f(coeffs, x1);
       fx2= f(coeffs, x2);

       if (fabs(fx1) < tolerance) { x0 = x1; fx0 = fx1; break; }
       if (fabs(fx2) < tolerance) { x0 = x2; fx0 = fx2; break; }
       
       if (fabs(fx2 - fx1) < 1e-12) cout << "Warning: Denominator small, may cause precision issues.\n";
       
       x0 = (x1 * fx2 - x2 * fx1) / (fx2 - fx1);
       fx0 = f(coeffs, x0);

       if (firstIteration) { relativeError =100.0; firstIteration = false; }
       else { relativeError = fabs ((x0 - prevx0) / x0) * 100; }
       
       cout << setw(4)  << iteration + 1 << " | "
            << setw(12) << fixed << setprecision(6) << x1 << " | "
            << setw(12) << x2 << " | "
             << setw(12) << x0 << " | "
             << setw(12) << fx0 << " | "
             << setw(12) << relativeError << " %\n";

        if (fabs(fx0) < tolerance) break;

        if (fx1 * fx0 < 0) x2 = x0;
        else x1 = x0;

        prevx0 = x0;
        iteration++;
     }
    while (iteration < maxIterations);

    cout << "-------------------------------------------------------------------------------\n";
    if (fabs(fx0) < tolerance) 
    { 
    cout << "✓ Convergence achieved!\n";
        cout << "Root approximation: " << fixed << setprecision(6) << x0 << endl;
        cout << "f(x) = " << scientific << setprecision(6) << fx0 << endl;
    }
    else {
        cout << "✗ Maximum iterations reached.\n";
        cout << "Best approximation: " << fixed << setprecision(6) << x0 << endl;
        cout << "f(x) = " << scientific << setprecision(6) << fx0 << endl;
         }
    cout << "Iteration: " << iteration + 1 << endl;
    }
 int main(){
    int degree;
    cout <<"===FALSE POSITION METHOD ( General Polynomial ) ===\n\n";

    cout << "Enter degree of polynomial: ";
    cin >> degree ; 
      
    vector<double> coeffs(degree + 1);
    cout << "Enter coefficients one by one (highest degree first):\n";
    for (int i = 0; i <= degree; i++) {
        cout << "a" << (degree - i) << " = ";
        cin >> coeffs[i];
    }

    double tolerance;
    int maxIterations;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIterations;

      double x1, x2;
    char choice;
    cout << "Do you want to use auto-generated initial guesses? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        if (!findinitialguesses(coeffs,x1,x2)) {
            cout << "Error: Could not find initial guesses automatically. Try manual input.\n";
            return 1;
        }
        cout << "Automatic initial guesses found: x1 = " << x1 << ", x2 = " << x2 << endl;
    } else {
        cout << "Enter first initial guess (x1): ";
        cin >> x1;
        cout << "Enter second initial guess (x2): ";
        cin >> x2;
    }

    falsePosition(coeffs, x1, x2, tolerance, maxIterations);

    return 0;
}

 






























































