/* Optimal Parking
 * http://uva.onlinejudge.org/external/113/11364.html
 * Minimize the total walking done given a list of store locations
 * Assume optimal parking
 */

#include <stdio.h>

int main(void)
{
  int num_cases;
  scanf("%d", &num_cases);

  int i;
  for (i = 0; i < num_cases; ++i) {
    int num_locations;
    scanf("%d", &num_locations);

    int j;
    int max = 0;
    int min = 100;
    for (j = 0; j < num_locations; ++j) {
      int pos;
      scanf("%d", &pos);
      if (pos < min) 
        min = pos;
      if (pos > max)
        max = pos;
    }
    printf("%d\n", (max - min) * 2);
  }
  return 0;
}
