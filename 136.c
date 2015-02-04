/* Ugly Numbers
 * http://uva.onlinejudge.org/external/1/136.pdf
 * Ugly numbers are numbers whose only prime factors are 2, 3, and 5
 * Find the 1500th ugly number
 */

#include <stdio.h>
#define MAX_NUM 1500

int main(void)
{
  /* Allocate array to hold ugly numbers */
  /* Set first value to 1 */
  int ugly_nums[ MAX_NUM ];
  ugly_nums[0] = 1;

  /* Fill array with multiples of 2, 3 and 5 */
  /* Ensure array values are strictly increasing */
  int i;
  int ptr_2, ptr_3, ptr_5;
  ptr_2 = ptr_3 = ptr_5 = 0;

  for (i = 1; i < MAX_NUM; i++) {
    int next_2 = ugly_nums[ptr_2] * 2;
    int next_3 = ugly_nums[ptr_3] * 3;
    int next_5 = ugly_nums[ptr_5] * 5;

    if (next_2 <= next_3 && next_2 <= next_5) {
      ugly_nums[i] = next_2;
      ptr_2++;
    }
    if (next_3 <= next_2 && next_3 <= next_5) {
      ugly_nums[i] = next_3;
      ptr_3++;
    }
    if (next_5 <= next_2 && next_5 <= next_3) {
      ugly_nums[i] = next_5;
      ptr_5++;
    }
  }

  printf("The %d'th ugly number is %d.\n", MAX_NUM, ugly_nums[MAX_NUM - 1] );
  return 0;
}
