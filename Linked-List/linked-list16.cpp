
// Find the middle node of a singly Linked-list :

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

void insert_AtTail(node *&head, int value)
{
    node *new_node = new node(value);
    node *temp = head;
    if (head == NULL)
    {
        head = new_node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}


void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int find_middle(node *head)
{
    node *ptr1 = head;
    node *ptr2 = head;
    while (ptr1 != NULL && ptr1->next !=NULL)
    {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next->next;
        
    }
    return ptr2->value;
}

int main()
{
    node *head = NULL;
    insert_AtTail(head, 2);
    insert_AtTail(head, 3);
    insert_AtTail(head, 7);
    insert_AtTail(head, 2);
    insert_AtTail(head, 5) ;
    insert_AtTail(head, 8);
    display(head);
    cout << find_middle(head);
    return 0;
}