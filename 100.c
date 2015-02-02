/* The 3n + 1 Problem
 * http://uva.onlinejudge.org/external/1/100.html
 * Given integers i and j, calculate the maximum cycle length for
 * any integer between i and j inclusive
 */

#include <stdio.h>

int hailstone_length(int n)
{
  int count = 1;
  while( n > 1 ) {
    if ( n % 2 ) {
      n = (3*n + 1) / 2;
      count += 2;
    }
    else {
      n /= 2;
      count++;
    }
  }
  return count;
}

int main(void)
{
  int i, j;
  while( scanf("%d %d", &i, &j) == 2 ) {

    int max_length = 0;
    int index = i;
    int limit = j;
    if ( i > j ) {
      index = j;
      limit = i;
    }

    for (index; index <= limit; ++index) {
      int current_length;
      current_length = hailstone_length(index);

      if ( current_length > max_length ) {
        max_length = current_length;
      }
    }
    printf("%d %d %d\n", i, j, max_length);
  }
  return 0;
}
