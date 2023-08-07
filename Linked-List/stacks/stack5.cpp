
// Delete at the bottom / any Index of a stack :

#include <iostream>
#include <stack>
using namespace std;

void delete_At(stack<int> &input, int index)
{
    stack<int> temp;
    int count = 0, length = input.size();
    while (count < length - index - 1)
    {
        int current = input.top();
        temp.push(current);
        input.pop();
        count++;
    }
    input.pop();

    while (not temp.empty())
    {
        int current = temp.top();
        input.push(current);
        temp.pop();
    }
}

int main()
{
    stack<int> input_stack;
    input_stack.push(1);
    input_stack.push(2);
    input_stack.push(3);
    input_stack.push(4);
    input_stack.push(5);
    delete_At(input_stack, 2);
    while (not input_stack.empty())
    {
        int current = input_stack.top();
        cout << current << endl;
        input_stack.pop();
    }

    return 0;
}