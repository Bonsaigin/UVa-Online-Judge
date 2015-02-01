/* 11727 Cost cutting
 * http://uva.onlinejudge.org/external/117/11727.pdf
 */
#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int median(int a, int b, int c)
{
/* Function found at:
 * http://stackoverflow.com/a/14676309
 * Bitwise XOR with equal bits returns 0
 *             with opposite bits returns 1
 * This makes the calculated min/max cancel out
 * the original values, leaving the median behind.
 */
  int mx, mn, md;

  mx = MAX(MAX(a,b),c);
  mn = MIN(MIN(a,b),c);
  md = a^b^c^mx^mn;

  return md;
}

int main(void)
{
  int num_cases;
  scanf("%d", &num_cases);

  int i;
  for(i = 0; i < num_cases; ++i) {
    int s[3];
    int j;
    for (j = 0; j < 3; ++j) {
      scanf("%d", &s[j]);
    }

    int winner;
    winner = median(s[0], s[1], s[2]);  

    printf("Case %d: %d\n", i + 1, winner);
  }
  return 0;
}
