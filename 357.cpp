//Author: Ian Gibson
//Let Me Count The Ways
//UVa 357
//http://uva.onlinejudge.org/external/3/357.pdf
//Count the different combinations of coins that can be
//used to produce n cents.

#include <cstdio>

#define MAX_N 6001

unsigned long long f[ MAX_N ] = {0};

void generateSequence(void)
{
  int i;
  for (i = 0; i < MAX_N; i++) f[i] += 1;
  for (i = 1; i < MAX_N; i++) f[i] += f[i-1];
  for (i = 2; i < MAX_N; i++) f[i] += f[i-2];
  for (i = 5; i < MAX_N; i++) f[i] += f[i-5];
  for (i = 10; i < MAX_N; i++) f[i] += f[i-10];
}

int main(void)
{
  generateSequence();
  int n;
  while(scanf("%d\n", &n) != EOF) {
    if (n < 5)
      printf("There is only 1 way to produce %d cents change.\n", n);
    else
      printf("There are %lld ways to produce %d cents change.\n", f[n/5], n);
  }
  return 0;
}
