
// Time-complexcity : O(n^2)
// space-complexcity : O(1)
// It is unstable sorting algorithm

#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(v[i], v[min_index]);
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
    selection_sort(input);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}
