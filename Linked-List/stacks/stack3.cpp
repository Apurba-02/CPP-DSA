// Copy a stack in same order :

#include <iostream>
#include <stack>
using namespace std;

stack<int> copy_stack(stack<int> &input)
{
    stack<int> temp;
    while (not input.empty())
    {
        int current = input.top();
        input.pop();
        temp.push(current);
    }

    stack<int> result;
    while (not temp.empty())
    {
        int current = temp.top();
        temp.pop();
        result.push(current);
    }
    return result;
}

int main()
{

    stack<int> input_stack;
    input_stack.push(1);
    input_stack.push(2);
    input_stack.push(3);
    input_stack.push(4);
    input_stack.push(5);

    stack<int> result_Stack = copy_stack(input_stack);
    while (not result_Stack.empty())
    {
        int current = result_Stack.top();
        cout << current << endl;
        result_Stack.pop();
    }
    return 0;
}
