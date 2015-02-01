#include <stdio.h>
/* GCD */
void swap(int* x, int* y)
{
  int t;
  t = *x;
  *x = *y;
  *y = t;
}

int gcd(int a, int b)
{
  while(b) {
    a %= b;
    swap(&a, &b);
  }

  return a;
}

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);

  while(n != 0) {
    int i, j;
    int g = 0;
    for(i = 2; i <= n; ++i) {
      for(j = i - 1; j < n; ++j) {
        g += gcd(j, i);
      }
    }
    printf("%d\n", g);
    scanf("%d", &n);
  }
  return 0;
}
