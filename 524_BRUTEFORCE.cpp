/* Prime Ring Problem
 * http://uva.onlinejudge.org/external/5/524.pdf
 */

#include <cstdio>
#include <algorithm>

bool isPrime(int x)
{
  if ( x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19) return true;
  else return false;
}

bool isPrimeRing(int* ring, int size)
{
  //when adding two odds, the result is even,
  //so no odds may be be in odd numbered indicies
  for (int i = 1; i < size - 1; i += 2) {
    if (ring[i] % 2) return false;
  }

  //if the evens/odds are in the right place, make sure 
  //their sums are prime
  for (int i = 0; i < size; i++) {
    if (!isPrime( ring[i] + ring[(i+1)%size] )) {
      return false;
    }
  }
  return true;
}

void printRing(int* ring, int size)
{
  for (int i = 0; i < size - 1; i++) {
    printf("%d ", ring[i]);
  }
  printf("%d\n", ring[size-1]);
}

int main(void)
{
  int n;
  int caseNum = 0;
  while ( scanf("%d\n", &n) != EOF) {
    if (caseNum) printf("\n");
    caseNum++;
    printf("Case %d:\n", caseNum);

    int ring[ n ];
    for (int i = 0; i < n; i++) {
      ring[i] = i + 1;
    }
    if (n % 2 == 0 || n == 1) {
      do {
        if (isPrimeRing(ring, n)) {
          printRing(ring, n);
        } 
      } while (std::next_permutation(ring + 1, ring + n));
    }
  }
  return 0;
}
