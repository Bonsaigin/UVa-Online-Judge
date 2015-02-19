#include <stdio.h>
#include <algorithm>

int num_books, money;
int prices[ 10001 ];

int binarySearch(int n, int start)
{
  int left = start;
  int right = num_books;
  while (left <= right) {
    int middle = ( right + left ) / 2;
    if ( prices[middle] == n )
      return middle;
    else if ( prices[middle] > n )
      right = middle - 1;
    else
      left = middle + 1;
  }
  return -1;

}

int main(void)
{
  while(scanf("%d\n", &num_books) == 1 ) {
    for (int i = 0; i < num_books; i++) {
      scanf("%d", &prices[i]);
    }
    scanf("%d", &money);

    std::sort(prices, prices + num_books);

    int result[ 10000 ];
    int a = 0;
    int i = 0;

    do {
      if ( binarySearch((money - prices[i]), i + 1 ) != -1 ) {
printf("a: %d; added %d\n", a, prices[i]);
        result[ a ] = prices[ i ];
        a++;
      }
      i++;
    } while (prices[i] < (money / 2));

for(int i=0; i<10;i++) {printf("%d: %d\n", i, result[i]);}
    printf("Peter should buy books whose prices are %d and %d.\n\n",
	result[ a-1 ], money - result[ a - 1 ]);
  }
  return 0;
}
