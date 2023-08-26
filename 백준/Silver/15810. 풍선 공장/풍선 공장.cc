#include <stdio.h>

using namespace std;
int n, m;
int arr[1000000];
int maxVal = -1;
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
    maxVal = arr[i] > maxVal ? arr[i] : maxVal;
  }
  long long start = 1, end = 1LL*maxVal*m;
  long long b;
  while (start + 1 < end)
  {
    b = 0;
    long long mid = start + (end - start) / 2;
    for (int i = 0; i < n; i++)
    {
      b += mid / arr[i];
    }

    if (b >= m)
    {
      end = mid;
    }
    else
    {
      start = mid;
    }
  }

  printf("%lld\n", end);
  return 0;
}