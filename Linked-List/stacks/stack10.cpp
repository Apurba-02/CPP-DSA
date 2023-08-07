#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int histogram_largest_rectangle_area(vector<int> &height)
{
    int area = 0;
    stack<int> index;
    int n = height.size();
    index.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!index.empty() and height[i] < height[index.top()])
        {
            int current_height = height[index.top()];
            index.pop();
            int next_smaller = i;
            int prev_smaller = (index.empty()) ? -1 : index.top();
            area = max(area, current_height * (next_smaller - prev_smaller - 1));
        }
        index.push(i);
    }

    while (!index.empty())
    {
        int current_height = height[index.top()];
        index.pop();
        int next_smaller = n;
        int prev_smaller = (index.empty()) ? -1 : index.top();
        area = max(area, current_height * (next_smaller - prev_smaller - 1));
    }
    return area;
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
    int largest_area = histogram_largest_rectangle_area(input);
    cout << largest_area;

    return 0;
}