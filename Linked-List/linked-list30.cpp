
// Deletionat the start and end of a a circularly linked list :

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

class circular_linkedlist
{
public:
    node *head;

    circular_linkedlist()
    {
        head = NULL;
    }

    void display()
    {
        node *temp = head;
        do
        {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    bool check_circular()
    {
        node *temp = head;
        do
        {
            temp = temp->next;
            if (temp->next == head)
            {
                return true;
            }
        } while (temp != NULL);
        return false;
    }

    void insert_AtEnd(int value)
    {
        node *new_node = new node(value);
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            head = new_node;
            return;
        }

        node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = new_node;
        new_node->next = head;
    }

    void delete_head()
    {
        node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = head->next;
        temp = head;
        head = head->next;
        free(temp);
    }

    void delete_tail()
    {
        node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next->next != head);
        free(temp->next->next);
        temp->next = head;
    }
};

int main()
{
    circular_linkedlist cll;
    cll.insert_AtEnd(10);
    cll.insert_AtEnd(8);
    cll.insert_AtEnd(6);
    cll.insert_AtEnd(4);
    cll.insert_AtEnd(2);
    cout << cll.check_circular() << endl;
    cll.display();
    cll.delete_head();
    cout << cll.check_circular() << endl;
    cll.display();
    cll.delete_tail();
    cout << cll.check_circular() << endl;
    cll.display();
    return 0;
}