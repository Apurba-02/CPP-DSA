
// Find the next greater element :

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> find_NextGreater(vector<int> &input)
{
    int n = input.size();
    vector<int> output(n, -1);
    stack<int> index;
    index.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!index.empty() and input[i] > input[index.top()])
        {
            output[index.top()] = input[i];
            index.pop();
        }
        index.push(i);
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arry;
    while (n--)
    {
        int x;
        cin >> x;
        arry.push_back(x);
    }
    vector<int> result = find_NextGreater(arry);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
