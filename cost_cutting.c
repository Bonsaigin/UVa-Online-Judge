#include <stdio.h>

int main(void)
{
  int num_cases;
  scanf("%d", &num_cases);

  int i;
  for(i = 0; i < num_cases; ++i) {
    int salaries[3];
    int j;
    for (j = 0; j < 3; ++j) {
      scanf("%d", &salaries[j]);
    }
    int winner;
        

    printf("Case %d: %d", i + 1, winner);
  }
  return 0;
}
