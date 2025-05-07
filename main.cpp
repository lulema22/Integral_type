#include "integr.h"
#include <vector>
#include <iostream>
#include <cmath>

int main() {
    double a= 0.0;
    double b= M_PI/2.0;
    func f = [](double x) {return std::sin(2.0*x)/3.0;};
    std::vector<int> Ns = {2,10,20,50};
    for (int n:Ns) {
        double h=(b - a)/n;
        double rec =rectangle(a, b, n,f);
        double trap= trapezoid(a, b, n, f);
        double simp =Simpson(  a, b, n,f);

        const double M2 = 4.0/3.0;
        const double M4 = 16.0/3.0;
        double R_mid  = (b - a)/4.0*h*h*M2;
        double R_trap = (b - a)/12.0* h*h* M2;
        double R_simp = (b - a) /180.0* std::pow(h,4) *M4;

        std::cout << "n= " << n << "\n";
        std::cout << "Площадь п-у = " << rec << " R п-у:  <= " << R_mid << "\n";
        std::cout << " Трапеция = " << trap<< " R трапеция  <= "<< R_trap << "\n";
        std::cout << " Simpson  = " << simp<< " R Simpsona " << R_simp << "\n\n";
    }

    return 0;
}
