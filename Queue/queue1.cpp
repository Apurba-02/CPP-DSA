
// Linked-list implementation of Queues :

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

class queue
{
    node *head;
    node *tail;
    int size;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueqe(int value)
    {
        node *new_node = new node(value);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void dequeue()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            node *temp = head;
            head = head->next;
            free(temp);
            size--;
        }
    }

    int get_size()
    {
        return size;
    }

    int front()
    {
        return head->value;
    }

    bool is_empty()
    {
        return head == NULL;
    }
};

int main()
{
    queue qu;
    cout << qu.get_size() << endl;
    cout << qu.is_empty() << endl;
    qu.enqueqe(5);
    qu.enqueqe(10);
    qu.enqueqe(15);
    qu.dequeue();
    qu.enqueqe(20);
    cout << qu.get_size() << endl;
    cout << qu.front() << endl;
    while (!qu.is_empty())
    {
        cout << qu.front() << endl;
        qu.dequeue();
    }
    return 0;
}