/* Biorhythms
 * http://uva.onlinejudge.org/external/7/756.html
 * Chinese Remainder Theorem Problem
 * Author: Ian Gibson
 * 2/17/2015
 */

#define P_CYCLE 23
#define E_CYCLE 28
#define I_CYCLE 33

#include <stdio.h>

int mod_inv(int a, int m)
{
  int m0 = m;
  int temp, q;
  int x0 = 0;
  int x1 = 1;

  if (m == 1) return 1;
  while (a > 1) {
    q = a / m;
    temp = m;
    m = a % m;
    a = temp;
    temp = x0;
    x0 = x1 - q * x0;
    x1 = temp;
  }
  return x1 < 0 ? x1 + m0 : x1;
}

int main(void)
{
  const int k = 3; //Number of congruences
  int p, e, i, d;
  int caseNum = 0;

  scanf("%d %d %d %d", &p, &e, &i, &d);
  while(p >= 0){ //only need to check one var
    int daysToPeak = 0;
    int z[k];
    int y[k];
    int a[k] = {p, e, i};
    int m[k] = {P_CYCLE, E_CYCLE, I_CYCLE};
    int M = P_CYCLE * E_CYCLE * I_CYCLE;
    caseNum++;

    /*We have :
     x = p % P_CYCLE
     x = e % E_CYCLE
     x = i % I_CYCLE
    */

    //Chinese Remainder Theorem Algorithm
    for (int j = 0; j < k; j++) {
      z[j] = M / m[j];
      y[j] = mod_inv(z[j], m[j]);
      daysToPeak += a[j] * y[j] * z[j];
    }

    daysToPeak %=M;
    //Subtract current date from date of next peak
    daysToPeak -= d;

    while (daysToPeak <= 0) {
      daysToPeak += M;
    }

    printf("Case %d: the next triple peak occurs in %d days.\n", caseNum, daysToPeak);
    scanf("%d %d %d %d", &p, &e, &i, &d);
  }
  return 0;
}
