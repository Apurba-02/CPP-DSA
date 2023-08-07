#include <iostream>
#include <stack>
using namespace std;

int delete_toBalance(string bracket_sequence)
{
    stack<char> brackets;
    int count = 0;

    for (int i = 0; i < bracket_sequence.size(); i++)
    {
        char ch = bracket_sequence[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            brackets.push(ch);
        }
        else
        {
            if (ch == ')' && !brackets.empty() && brackets.top() == '(')
            {
                brackets.pop();
            }
            else if (ch == '}' && !brackets.empty() && brackets.top() == '{')
            {
                brackets.pop();
            }
            else  if (ch == ']' && !brackets.empty() && brackets.top() == '[')
            {
                brackets.pop();
            }
            count++;
        }
    }
    return  count;
}

int main(){
    string input = "({[(])";
    cout<<delete_toBalance(input);
    return 0;
}
