
// Reverse the elements of a Queue :

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverse(queue<int> &input)
{
    stack<int> temp;
    while (!input.empty())
    {
        int current = input.front();
        temp.push(current);
        input.pop();
    }

    while (!temp.empty())
    {
        int current = temp.top();
        input.push(current);
        temp.pop();
    }
}

int main()
{
    queue<int> qu;
    qu.push(5);
    qu.push(10);
    qu.push(15);
    qu.push(20);
    qu.push(25);
    reverse(qu);
    while (!qu.empty())
    {
        cout << qu.front() << endl;
        qu.pop();
    }
    return 0;
}