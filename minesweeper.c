#include <stdio.h>

int main(void)
{
  int n, m;
  scanf("%d %d", &n, &m);
  int field_num = 0;  

  while(n != 0) {
    char field[n][m];

    int i, j;
    for(i = 0; i <= n; ++i) {
      for(j = 0; j < m; ++j) {
        field[i][j] = getchar();
      }
    }
    ++field_num;
    printf("Field #%d", field_num);
    printf("%s\n", field);
    scanf("%d %d", &n, &m);
  }
  return 0;
}
