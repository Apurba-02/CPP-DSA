// Insert at the bottom / any Index of a stack :

#include <iostream>
#include <stack>
using namespace std;

stack<int> insert_atBottom(stack<int> &input, int value)
{
    stack<int> temp;
    while (not input.empty())
    {
        int current = input.top();
        temp.push(current);
        input.pop();
    }
    input.push(value);

    while (not temp.empty())
    {
        int current = temp.top();
        input.push(current);
        temp.pop();
    }
    return input;
}

void insert_At(stack<int> &input, int index, int value)
{
    int count = 0, length = input.size();
    stack<int> temp;
    while (count < length-index)
    {
        int current = input.top();
        temp.push(current);
        input.pop();
        count++;
    }
    input.push(value);

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
    insert_atBottom(input_stack, 0);
    insert_At(input_stack, 2, 6);
    while (not input_stack.empty())
    {
        int current = input_stack.top();
        cout << current << endl;
        input_stack.pop();
    }
    return 0;
}