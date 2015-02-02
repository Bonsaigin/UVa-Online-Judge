/* Division of Nlogonia
 * http://uva.onlinejudge.org/external/114/p11498.pdf
 * Given a point to represent the origin of X and Y axes,
 * determine which quadrant a point lies in
 */

#include <stdio.h>

int main(void)
{
  int num_pts;
  scanf("%d", &num_pts);

  while ( num_pts ) {
    int div_pt[2];
    scanf("%d %d", &div_pt[0], &div_pt[1]);

    int i;
    int curr_pt[2];
    for (i = 0; i < num_pts; ++i) {
      scanf("%d %d", &curr_pt[0], &curr_pt[1]);
      if ( curr_pt[0] == div_pt[0] || curr_pt[1] == div_pt[1] ) {
        printf("divisa\n");
      }
      else if ( curr_pt[0] < div_pt[0] ) {
        if ( curr_pt[1] < div_pt[1] ) {
          printf("SO\n");
        }
        else {
          printf("NO\n");
        }
      }
      else {
        if ( curr_pt[1] < div_pt[1] ) {
          printf("SE\n");
        }
        else {
          printf("NE\n");
        }
      }
    }

    scanf("%d", &num_pts);
  }
  return 0;
}
