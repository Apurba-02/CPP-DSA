
// Insertion at the start of a dubly linked list :

#include <iostream>
#include <ostream>
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

    void insert_atStart(int value)
    {
        node *new_node = new node(value);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head=new_node;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
           std:: cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << endl;
    }
};

int main()
{
    dubly_linkedlist dll;
    dll.insert_atStart(7);
    dll.insert_atStart(2);
    dll.insert_atStart(9);
    dll.insert_atStart(22);
    dll.insert_atStart(51);
    dll.display();
    return 0;
}