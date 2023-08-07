
// Time-complexcity : O(n^2)
// space-complexcity : O(1)
// Maximum swap = n(n-1/2)
// It is stable sorting algorithm

#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &v)
{
    int n = v.size(), i, j;
    bool flag = false;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                flag = true;
            }
            if (flag == false)
            {
                break;
            }
        }
    }
}

int main()
{
    vector<int> input;
    cout << "Enter size of the array : \n";
    int n;
    cin >> n;
    cout << "Enter the elemements of the array : \n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        input.push_back(x);
    }
    bubble_sort(input);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}