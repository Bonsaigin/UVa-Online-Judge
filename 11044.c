/* Searching for Nessy
 * http://uva.onlinejudge.org/external/110/11044.html
 * Determine the minimum number of 3x3 squares to cover
 * an n x m grid (ignoring borders)
 */

#include <stdio.h>

int main(void)
{
  int num_cases;
  scanf("%d", &num_cases);

  int i;
  for (i = 0; i < num_cases; ++i) {
    int n, m;
    scanf("%d %d", &n, &m);

    int s = (n/3) * (m/3);
    printf("%d\n", s);
  }
  return 0;
}
