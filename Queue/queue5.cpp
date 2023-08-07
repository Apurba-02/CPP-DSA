
// Implementation of queue using stack (Push-efficient) :

#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> st;

public:
    queue(){};

    void push(int value)
    {
        st.push(value);
    }

    void pop()
    {
        stack<int> temp;
        while (st.size() > 1)
        {
            temp.push(st.top());
            st.pop();
        }
        st.pop();

        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }

    int front()
    {
        stack<int> temp;
        while (st.size() > 1)
        {
            temp.push(st.top());
            st.pop();
        }
        int result= st.top();

        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return result;
    }

    int get_size(){
        return st.size();
    }

    bool is_empty(){
        return st.empty();
    }
};

int main()
{
    queue qu;
    cout << qu.get_size() << endl;
    cout << qu.is_empty() << endl;
    qu.push(5);
    qu.push(10);
    qu.push(15);
    qu.pop();
    qu.push(20);
    cout << qu.get_size() << endl;
    cout << qu.front() << endl;
    while (!qu.is_empty())
    {
        cout << qu.front() << endl;
        qu.pop();
    }
    return 0;
}
