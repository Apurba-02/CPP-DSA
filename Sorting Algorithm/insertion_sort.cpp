
// Time-complexcity : O(n^2)
// space-complexcity : O(1)
// It is stable sorting algorithm

#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int curr_ele = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > curr_ele)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = curr_ele;
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
    insertion_sort(input);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}