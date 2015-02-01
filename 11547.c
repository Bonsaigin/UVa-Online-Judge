#include <stdio.h>
/* Automatic Answer */
int main(void)
{
  int num_cases;
  scanf("%d", &num_cases);

  int i;
  for(i = 0; i < num_cases; ++i) {
    int n;
    scanf("%d", &n);
    n = ((n * 315) + 36962);
    printf("%d\n", abs((n / 10) % 10));
  }
  return 0;
}
