
// Implementation of Deque using dubly-linkedlist:

#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
    node *prev;

    node(int data)
    {
        value = data;
        next = NULL;
        prev = NULL;
    }
};

class deque
{
    node *head;
    node *tail;
    int size;

public:
    deque()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push_back(int value)
    {
        node *new_node = new node(value);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            tail->prev = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
    }

    void push_front(int value)
    {
        node *new_node = new node(value);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            tail->prev = new_node;
        }

        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "underflow" << endl;
            return;
        }
        else
        {
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
            size--;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "underflow" << endl;
            return;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
            size--;
        }
    }

    int front()
    {
        return head->value;
    }

    int back()
    {
        return tail->value;
    }

    int get_size()
    {
        return size;
    }

    bool is_empty()
    {
        return head == NULL;
    }
};

int main()
{
    deque dq;
    dq.push_back(5);
    dq.push_back(15);
    dq.push_back(25);
    cout << dq.front() << endl;
    dq.push_front(35);
    dq.push_front(45);
    cout << dq.get_size() << endl;
    cout << dq.front() << endl;
    dq.pop_front();
    cout << dq.front() << endl;
    dq.pop_back();
    cout << dq.back() << endl;
    cout << dq.get_size() << endl;
    cout << dq.is_empty() << endl;
    return 0;
}