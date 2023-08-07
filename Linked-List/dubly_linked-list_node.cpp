#include <iostream>
#include<ostream>
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

class dubly_linkedlist
{
public:
    node *head;
    node *tail;

    dubly_linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
};

int main()
{
    node *new_node = new node(5);
    dubly_linkedlist dll;
    dll.head = new_node;
    dll.tail = new_node;
    cout << dll.head->value;
    return 0;
}