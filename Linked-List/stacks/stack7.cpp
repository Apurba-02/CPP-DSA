
// Bracket sequense :

#include <iostream>
#include <stack>
using namespace std;

bool is_valid(string input)
{
    stack<char> barackets;
    for (int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        if (ch == '(' or ch == '{' or ch == '[')
        {
            barackets.push(ch);
        }
        else
        {
            if (ch == ')' and !barackets.empty() and barackets.top() == '(')
            {
                barackets.pop();
            }
            else if (ch == '}' and !barackets.empty() and barackets.top() == '{')
            {
                barackets.pop();
            }
            else if (ch == ']' and !barackets.empty() and barackets.top() == '[')
            {
                barackets.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return barackets.empty();
}

int main()
{
    string str = "{({{}})}";
    cout << is_valid(str) << endl;
    return 0;
}