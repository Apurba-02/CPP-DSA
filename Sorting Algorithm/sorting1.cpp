
// Bubble_Sort :

#include <iostream>
#include <vector>
using namespace std;

void zeros_AtEnd(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] == 0 && v[j + 1] != 0)
            {
                swap(v[j], v[j + 1]);
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
    zeros_AtEnd(input);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}
