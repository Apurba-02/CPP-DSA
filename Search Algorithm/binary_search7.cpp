#include <iostream>
using namespace std;

int search(int arry[], int terget, int length)
{
    int start = 0, end = length - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2 ;
        if (terget == arry[mid])
        {
            return mid ;
        }
        if (arry[start] <= arry[mid])
        {

            if (terget >= arry[start] and terget <= arry[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (terget <= arry[end] and terget >= arry[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
  int arry[] = {4, 5 ,6 , 7 , 0 , 1 , 2 , 3}, terget, length;
  length = sizeof(arry) / sizeof(int);
  cout<<"Enter the number to search : \n";
  cin>>terget;
  cout<<search(arry , terget , length);
  return 0;
}