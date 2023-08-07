
// Merge two sorted linked-list :

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

void insert(node *&head, int value)
{
    node *new_node = new node(value);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    node *temp = head;
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

node *merge_LL(node *&head1, node *&head2)
{
    node *dummy_head = new node(-1);
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = dummy_head;
    while (ptr1 && ptr2)
    {
        if (ptr1->value < ptr2->value)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    if (ptr1)
    {
        ptr3->next = ptr1;
    }
    else
    {
        ptr3->next = ptr2;
    }
    return dummy_head->next;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    insert(head1 ,1);
    insert(head1 ,4);
    insert(head1 ,5);
    insert(head2 ,2);
    insert(head2 ,3);
    node *head = merge_LL(head1 , head2);
    display(head);
    return 0;
}