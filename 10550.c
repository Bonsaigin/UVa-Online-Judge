/* Combination Lock
 * http://uva.onlinejudge.org/external/105/10550.html
 * Given the starting position of a dial, and the combination,
 * Calculate the number of degrees a 40-number dial must be turned
 */

#include <stdio.h>
#define MAX_NUM 40

/* Distance functions
 * These functions implement a MOD operator since
 * C's % represents the remainder operator
 */
int dist_cw(int curr, int next)
{

  int  r = (curr - next) % MAX_NUM;
  return r < 0 ? (r + MAX_NUM) : r;
}

int dist_ccw(int curr, int next)
{
  int r = (next - curr) % MAX_NUM;
  return r < 0 ? (r + MAX_NUM) : r;
}

int main(void)
{
  int start_pos;
  int comb[3];
  
  scanf("%d %d %d %d", &start_pos, &comb[0], &comb[1], &comb[2]);

  while (start_pos || comb[0] || comb[1] || comb[2]) {
    int dist = 2 * MAX_NUM;              /* 2 initial rotations   */
    printf("%d\n", dist);
    dist += dist_cw(start_pos, comb[0]); /* stop at first number  */
    printf("%d\n", dist);
    dist += MAX_NUM;                     /* 1 ccw turn            */
    printf("%d\n", dist);
    dist += dist_ccw(comb[0], comb[1]);  /* stop at second number */
    printf("%d\n", dist);
    dist += dist_cw(comb[1], comb[2]);   /* stop at third number  */
    printf("%d\n", dist);

    int degrees = 9 * dist;
    printf("%d\n", degrees);
    scanf("%d %d %d %d", &start_pos, &comb[0], &comb[1], &comb[2]);
  }
  return 0;
}
