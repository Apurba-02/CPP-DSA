#include <iostream>
using namespace std;
int search_peak(int arry[], int length)
{
    int start = 0, end = length - 1, index;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arry[mid - 1] < arry[mid])
        {
            index = mid;
            start = mid + 1;
        }
        if (arry[mid - 1] > arry[mid])
        {
            end = mid - 1;
        }
    }
    return index;
}

int main()
{
    int arry[] = {0 ,2,4, 3 ,0 , -1},length;
    length = sizeof(arry) / sizeof(int);
    cout<<search_peak(arry, length);
    return 0;
}