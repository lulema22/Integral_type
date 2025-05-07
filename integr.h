#ifndef INTEGR_H
#define INTEGR_H

#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <iomanip>
using func = std::function<double(double)>;


double rectangle(double a, double b, int n, func f) {
    double h = (b-a)/n;
    double sum = 0.0;
    for (int i =0; i < n; i++) {
      double x = a + h*(i+0.5);
      sum += f(x);
    }
    return sum*h;
  }


double trapezoid(double a, double b, int n, func f) {
  double h = (b-a)/n;
  double sum_sum = 0.0;
  for (int i =0; i < n; i++) {
   double x_1 = a + h*i;
   double x_2 = a + h*(i+1);
   double sum = f(x_1) + f(x_2);
   sum_sum += sum;
  }
  return sum_sum*h/2.0;
}

double Simpson(double a, double b, int n, func f) {
  if (n%2 != 0) {
    throw std::invalid_argument("n не кратно 2");
  }
  double h = (b-a)/n;
  double sum_sum = f(a) + f(b);
  for (int i =1; i < n; i++) {
    double x = a + i*h;
    if (i % 2 == 0) sum_sum += 2*f(x);
     else   sum_sum += 4*f(x);
  }
  return sum_sum*h/3.0;

}






#endif //INTEGR_H
