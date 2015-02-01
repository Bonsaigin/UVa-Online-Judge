#include <stdio.h>
#define MAX_NUM 5


int main(void)
{
  long number = 1;
  int count = 1;

  for(number = 1; count < MAX_NUM; ++number) {
    if(number % 2 == 0) continue;
    if(number % 3 == 0) continue;
    if(number % 5 == 0) continue;
    printf("%ld\n", number);
    ++count;
  }

  printf("The %d'th ugly number is %ld\n", MAX_NUM, number);
  return 0;
}
