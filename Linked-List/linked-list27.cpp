
// chack a Dubly-LL is palinederone or not :

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

    bool check_Palinedrome()
    {
        while (head != tail && tail != head->prev)
        {
            if (head->value != tail->value)
            {
                return false;
            }
            head = head->next;
            tail = tail->prev;
        }
        return true;
    }
};

int main()
{
    dubly_linkedlist dll;
    dll.insert_AtTail(3);
    dll.insert_AtTail(5);
    dll.insert_AtTail(7);
    dll.insert_AtTail(7);
    dll.insert_AtTail(5);
    dll.insert_AtTail(3);
    dll.display();
    std::cout << dll.check_Palinedrome();
    return 0;
}