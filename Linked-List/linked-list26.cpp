
// Reverse a dubly linked list :

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

    void insert_AtTail(int value)
    {
        node *new_node = new node(value);
        if (tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << endl;
    }

    void reverse()
    {
        node *current = head;
        while (current != NULL)
        {
            node *then = current->next;
            current->next = current->prev;
            current->prev = then;
            current = then;
        }
        node *new_head = tail;
        tail = head;
        head = new_head;
    }
};

int main()
{
    dubly_linkedlist dll;
    dll.insert_AtTail(3);
    dll.insert_AtTail(5);
    dll.insert_AtTail(7);
    dll.insert_AtTail(9);
    dll.display();
    dll.reverse();
    dll.display();
    return 0;
}