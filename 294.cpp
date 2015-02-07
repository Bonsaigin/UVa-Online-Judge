#include <stdio.h>
#include <math.h>

int main(void)
{
  int num_cases;
  scanf("%d", &num_cases);
  for (int i = 0; i < num_cases; i++) {
    int L, U;
    scanf("%d %d", &L, &U);

    int currP;
    int P = 0;
    int D = 0;
    for(currP = L; currP <= U; currP++) {
      int currD;
      int numD = 0;
      int sqroot = (int) sqrt(currP) + 1;
      for(currD = 1; currD < sqroot; currD++) {
        if (currP % currD == 0) {
          if ( (int) pow(currD, 2) != currP) {
            numD++;
          }
          numD++; 
        }
      }
      if (numD > D && currP > P) {
        D = numD;
        P = currP;
      }
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, P, D);
  }
  return 0;
}
