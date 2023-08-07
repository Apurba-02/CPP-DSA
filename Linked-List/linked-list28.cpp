
// Delete nodes having same neighbour (Dubly-LL) :

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

    void delete_node()
    {
        node *current = tail->prev;
        while (current != head)
        {
            node *back = current->prev;
            if (current->next->value == current->prev->value)
            {
                current->next->prev = current->prev;
                current->prev->next = current->next;
                free(current);
                current = back;
            }
            current = back;
        }
    }
};

int main()
{
    dubly_linkedlist dll;
    dll.insert_AtTail(2);
    dll.insert_AtTail(1);
    dll.insert_AtTail(1);
    dll.insert_AtTail(2);
    dll.insert_AtTail(1);
    dll.display();
    dll.delete_node();
    dll.display();
    return 0;
}