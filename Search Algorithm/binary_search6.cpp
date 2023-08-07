#include <iostream>
using namespace std;
int search_min(int arry[], int length)
{
  int start = 0, end = length - 1;
  if (length == 1)
  {
    return 0;
  }
  if (arry[start] < arry[end])
  {
    return start;
  }
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arry[mid + 1] < arry[mid])
    {
      return mid + 1;
    }
    if (arry[mid - 1] > arry[mid])
    {
      return mid;
    }
    if (arry[start] < arry[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int arry[] = {3, 4, 5, 1, 2}, index, length;
  length = sizeof(arry) / sizeof(int);
  index = search_min(arry, length);
  cout << index;
  return 0;
}