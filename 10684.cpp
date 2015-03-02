#include <cstdio>
#include <climits>

long long maxSum(int* array, int size)
{
  long long maxSum = LLONG_MIN;
  int maxStart = 0;
  int maxEnd = 0;
  int currentSum = 0;
  int currentStart = 0;

  for (int currentEnd = 0; currentEnd < size; currentEnd++) {
    currentSum += array[currentEnd];
    if (currentSum > maxSum) {
      maxSum = currentSum;
      maxStart = currentStart;
      maxEnd = currentEnd;
    }
    if (currentSum < 0) {
      currentSum = 0;
      currentStart = currentEnd + 1;
    }
  }
  return maxSum;
}

int main(void)
{
  int N;
  scanf("%d\n", &N);

  while (N) {
    int seq[N];
    for (int i = 0; i < N; i++) {
      scanf("%d", &seq[i]);
    }

    long long streak = maxSum(seq, N);
    if (streak > 0) printf("The maximum winning streak is %lld.\n", streak);
    else printf("Losing streak.\n");
    
    scanf("%d\n", &N);
  }
  return 0;
}
