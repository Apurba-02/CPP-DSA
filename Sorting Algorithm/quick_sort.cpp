
// Time-complexcity : O(n^2)
// space-complexcity : O(n)
// It is unstable sorting algorithm

#include <iostream>
using namespace std;

int partition(int array[], int start, int end)
{
    int pivote_ele = array[end];
    int j, i = start - 1;
    for (j = start; j < end; j++)
    {
        if (array[j] < pivote_ele)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[end]);
    return i + 1;
}

void quick_Sort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pi = partition(array, start, end);
    quick_Sort(array, start, pi - 1);
    quick_Sort(array, pi + 1, end);
}

int main()
{
    int n;
    cout << "Enter the size of the arry : \n";
    cin >> n;
    int input[n];
    cout << "Enter the elements of the array : \n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        input[i] = x;
    }
    quick_Sort(input, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}