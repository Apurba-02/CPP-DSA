
// Stack implementation using Array :

#include <iostream>
using namespace std;

class stack
{
    int capacity;
    int *arry;
    int top;

public:
    stack(int c)
    {
        capacity = c;
        arry = new int[c];
        top = -1;
    }

    void push(int data)
    {
        if (top == capacity - 1)
        {
            cout << "Overflow \n";
            return;
        }
        top++;
        arry[top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow \n";
            return;
        }
        top--;
    }

    int get_top()
    {
        if (top == -1)
        {
            cout << "Underflow \n";
            return INT64_MIN;
        }
        return arry[top];
    }

    int size()
    {
        return top + 1;
    }

    bool is_full()
    {
        return top == capacity - 1;
    }

    bool is_empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st(3);
    cout << st.is_empty() << endl;
    st.pop();
    st.push(2);
    st.push(4);
    cout << st.size() << endl;
    st.push(6);
    cout << st.is_full() << endl;
    st.push(8);
    st.pop();
    cout << st.get_top() << endl;
    return 0;
}