#include <iostream>
using namespace std;

int lowerBound(int arry[], int length, int terget)
{
    int start = 0, end = length - 1, index = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (terget > arry[mid])
        {
            start = mid + 1;
        }
        else if (terget <= arry[mid])
        {
            index = mid;
            end = mid - 1;
        }
    }
    return index;
}

int upperBound(int arry[], int length, int terget)
{
    int start = 0, end = length - 1, index = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (terget >= arry[mid])
        {
            start = mid + 1;
        }
        else if (terget < arry[mid])
        {
            index = mid;
            end = mid - 1;
        }
    }
    return index;
}

int main()
{
    int arry[] = {1, 2, 3, 3, 3, 5, 11}, index[2], terget, length = sizeof(arry) / sizeof(arry[0]);
    cout << "Enter the number to search : \n";
    cin >> terget;
    index[0] = lowerBound(arry, length, terget);
    index[1] = upperBound(arry, length, terget);
    cout << index[0] << " , " << index[1];
    return 0;
}