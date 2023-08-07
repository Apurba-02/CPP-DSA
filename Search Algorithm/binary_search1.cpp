
//Time Complexcity : O(log N)

#include <iostream>
using namespace std;
int main()
{

    int arry[] = {1, 11, 21, 31, 41, 51, 61, 71, 81, 91}, index = -1;
    int length = sizeof(arry) / sizeof(int), start = 0, end = length - 1, middle = end + (start-end)/2, x;
    cout << "Enter the number to search : \n";
    cin >> x;
    while (start < end)
    {
        if (x > arry[middle])
        {
            start = middle + 1;
        }
        else if (x == arry[middle])
        {
            index = middle;
            cout << "index : " << index;
            break;
        }
        else if (x < arry[middle])
        {
            end = middle - 1;
        }
        middle = (start + end) /2;
    }

    if (index == -1)
    {
        cout << "Not found!!";
    }
    return 0;
}