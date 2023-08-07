
// calculate span of a stock :

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> previus_Greater(vector<int> &stock_arry)
{
    int n = stock_arry.size();
    reverse(stock_arry.begin(), stock_arry.end());
    vector<int> output(n, -1);
    stack<int> index;
    index.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!index.empty() and stock_arry[i] > stock_arry[index.top()])
        {
            output[index.top()] = n - i - 1;  // on reversing index changes
            index.pop();
        }
        index.push(i);
    }
    reverse(output.begin(), output.end());
    reverse(stock_arry.begin(), stock_arry.end());
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input;
    while (n--)
    {
        int x;
        cin >> x;
        input.push_back(x);
    }
    vector<int> result = previus_Greater(input);
    for (int i = 0; i < result.size(); i++)
    {
        cout << (i - result[i]) << " ";
    }
    return 0;
}
