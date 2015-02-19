/* Solve it
 * http://uva.onlinejudge.org/external/103/10341.html
 * Find the root of an equation!
 * Since this problem was intended as a divide an conquer problem, 
 * the bisection method is implemented. However Newtown's algorithm
 * typically requires less iterations
 */

#include <cstdio>
#include <cmath>

#define EPSILON 1e-7

int p, q, r, s, t, u;

double f(double x)
{
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double fprime(double x)
{
  return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;
}

double bisection()
{
  double low = 0;
  double high = 1;
  while (low + EPSILON < high) {
    double x = (low + high) / 2;
    if (f(low) * f(x) <= 0) {
      high = x;
    }
    else {
      low = x;
    }
  }
  return (low + high) / 2;
}

double newton()
{
  if (f(0)==0) return 0;
  for (double x=0.5;;) {
    double x1 = x - f(x)/fprime(x);
    if (fabs(x1-x) < EPSILON) return x;
    x = x1;
  }
}

int main(void)
{
  while (scanf("%d %d %d %d %d %d\n", &p, &q, &r, &s, &t, &u) != EOF) {
    if (f(0) * f(1) > 0) {
      printf("No solution\n");
    }
    else {
      printf("%.4lf\n", newton());
    }
  }
  return 0;
}
