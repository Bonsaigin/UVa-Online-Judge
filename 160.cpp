/* Factors and Factorials
 * http://uva.onlinejudge.org/external/1/160.pdf
 * Assume 2 <= N <= 100
 */

#include <stdio.h>

int prime_index[ 25 ] = {  2,  3,  5,  7, 11,
                          13, 17, 19, 23, 29,
                          31, 37, 41, 43, 47,
                          53, 59, 61, 67, 71,
                          73, 79, 83, 89, 97};

int main(void)
{
  int N;
  scanf("%d", &N);

  while (N) {
    int arr[ 25 ] = {0}; // there are 25 primes < 100
    printf("%3d! =", N);
    while (N != 1) {
      int i = N;
      int j = 0;
      while (i > 1) {
        int count = 0;
        while (i % prime_index[j] == 0) {
          i /= prime_index[j];
          count++;
        }
        arr[j] += count;
        j++;
      }
      N--;
    }

    for(int i = 0; arr[i] != 0; i++) {
      if (i == 15) printf("\n      ");
      printf("%3d", arr[i]);
    }
    printf("\n");

    scanf("%d", &N);
  }
  return 0;
}
