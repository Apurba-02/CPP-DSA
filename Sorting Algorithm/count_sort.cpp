
// time-complexcity: O(n)
// space-complexcity :O(n)
// It is stable sorting algorithm

#include <iostream>
#include <vector>
using namespace std;

void count_Sort(vector<int> &v)
{
    int n = v.size();
    int max_ele = 0;

    // find max element:

    for (int i = 0; i < n; i++)
    {
        max_ele = max(max_ele, v[i]);
    }

    // find frequency of each elements:

    vector<int> freq(max_ele + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }

    // calculate cumulative-frequency:

    for (int i = 1; i <= max_ele; i++)
    {
        freq[i] += freq[i - 1];
    }

    // calculate the sorted array:

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--freq[v[i]]] = v[i];
    }

    // copy to the input array:

    for (int i = 0; i < n; i++)
    {
        v[i] = ans[i];
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
    count_Sort(input);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}
