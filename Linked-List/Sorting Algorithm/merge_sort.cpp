
// Time-complexcity : O(n log n)
// space-complexcity : O(n)
// It is stable sorting algorithm

#include <iostream>
using namespace std;

void merge(int arry[], int start, int mid, int end)
{
    int an = mid - start + 1;
    int bn = end - mid;
    int a[an], b[bn];

    for (int i = 0; i < an; i++)
    {
        a[i] = arry[start + i];
    }
    for (int j = 0; j < bn; j++)
    {
        b[j] = arry[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while (i < an && j < bn)
    {
        if (a[i] < b[j])
        {
            arry[k++] = a[i++];
        }
        else
        {
            arry[k++] = b[j++];
        }
    }
    while (i < an)
    {
        arry[k++] = a[i++];
    }

    while (j < bn)
    {
        arry[k++] = b[j++];
    }
}

void merge_Sort(int arry[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge_Sort(arry, start, mid);
    merge_Sort(arry, mid + 1, end);
    merge(arry, start, mid, end);
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
    merge_Sort(input, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}