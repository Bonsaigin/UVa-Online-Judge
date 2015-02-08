#include <stdio.h>
#include <math.h>

int main(void)
{
  int N, C;
  while(scanf("%d %d", &N, &C) == 2) {
  
  bool primes[ N ];
  for (int b = 2; b <= N; b++) {
    primes[b] = true;
  }

  int sqroot = (int) sqrt(N) + 1;
  for (int i = 2; i < sqroot; i++) {
    if (primes[i]) {
      for (int j = i*i; j <= N; j += i) {
        primes[j] = false;
      }
    }
  }
  int numPrimes = 0;
  for (int p = 2; p <= N; p++) {
    if (primes[p]) numPrimes++;
  }

  printf("%d %d:", N, C);
  if (numPrimes % 2 != 0) {
    C = 2 * C;
  }
  else {
    C = 2 * C - 1;
  }
  if (C > numPrimes) {
    printf(" 1");
    C = numPrimes;
  }
  int numPrinted = 0;
  int numFound = 0;
  int printStart = ( numPrimes - C ) > 0 ? (numPrimes - C) / 2 : 0;
  for (int i = 2; numPrinted < C; i++) {
    if (primes[i]) {
      if (numFound >= printStart) {
        printf(" %d", i);
        numPrinted++;
      }
      numFound++;
    }
  }  
  printf("\n\n");
  }
  return 0;
}
