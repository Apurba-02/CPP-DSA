// Stack implementation using Linked-list :

#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;

    node(int data)
    {
        value = data;
        next = NULL;
    }
};

class stack
{
    int capacity;
    node *head;
    int size;

public:
    stack(int c)
    {
        this->capacity = c;
        this->head = NULL;
        this->size = 0;
    }

    void push(int value)
    {
        node *new_node = new node(value);

        if (this->size == this->capacity)
        {
            cout << "Overflow \n ";
            return;
        }
       
                new_node->next=this->head;
                this->head = new_node;
                this->size++;
                return;
    }

    void pop()
    {
        if (this->head == NULL)
        {
            cout << "Underflow \n";
            return;
        }
        node *temp = this->head;
        this->head = this->head->next;
        this->size--;
        free(temp);
    }

    int get_top()
    {
        if (this->size == 0)
        {
            cout<<"Underflow \n";
            return INT64_MIN;
            
        }
        return this->head->value;
    }

    int get_size()
    {
        return this->size;
    }

    bool is_empty()
    {
        if (this->head == NULL)
        {
            return true;
        }
        return false;
    }

    bool is_full()
    {
        return this->size == this->capacity;
    }
};

int main()
{

    stack st(3);
    cout << st.is_empty() << endl;
    st.pop();
    st.push(2);
    st.push(4);
    cout << st.get_size() << endl;
    st.push(6);
    cout << st.is_full() << endl;
    st.push(8);
    st.pop();
    cout << st.get_top() << endl;
    return 0;
}
