#include <iostream>
#include <vector>
using namespace std;

void count_sort(vector<int> &v, int pos)
{
    int n = v.size();
    vector<int> freq(10, 0);
    for (int i = 0; i < n; i++)
    {
        freq[(v[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--freq[(v[i] / pos) % 10]] = v[i];
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = ans[i];
    }
}

void radix_Sort(vector<int> &v)
{
    int n = v.size();
    int max_ele = 0;
    for (int i = 0; i < n; i++)
    {
        max_ele= max(v[i], max_ele);
    }
    int pos;
    for (pos = 1; max_ele / pos > 0; pos *= 10)
    {
        count_sort(v, pos);
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
    radix_Sort(input);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}

