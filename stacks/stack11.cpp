
// Find the min value in a stack :

// Time-Complexcity = O(1);

#include <iostream>
using namespace std;

class MinStack
{
    int capacity;
    int *arry;
    int size;

public:
    int min;

    MinStack(int c)
    {
        capacity = c;
        arry = new int[c];
        size = -1;
        min = 0;
    }

    bool empty()
    {
        return size == -1;
    }

    void push(int value)
    {
        if (size == -1)
        {
            min = value;
            size++;
            arry[size] = value;
        }
        else
        {
            size++;
            arry[size] = value - min;
            if (value < min)
            {
                min = value;
            }
        }
    }

    void pop()
    {
        if (size != -1)
        {
            if (arry[size] >= 0)
            {
                size--;
            }
            else
            {
                min = min - arry[size];
                size--;
            }
        }
    }

    int top()
    {
        if (size == 0)
        {
            return arry[0];
        }
        else if (arry[size] < 0)
        {
            return min;
        }
        else
        {
            return min + arry[size];
        }
    }

    int get_min()
    {
        return min;
    }
};

int main()
{
    MinStack st(6);
    st.push(3);
    st.push(0);
    st.push(5);
    st.push(-2);
    st.push(7);
    st.push(-5);
    cout << st.get_min() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.get_min() << endl;
    cout << st.top() << endl;
    return 0;
}
