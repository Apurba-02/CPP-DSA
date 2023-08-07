
// Reverse a linked-list :

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

node *reverse(node *&head)
{
    node *prev = NULL;
    node *current = head;
    node *then;

    while (current != NULL)
    {
        then = current->next;
        current->next = prev;
        prev = current;
        current = then;
    }
    return prev;
}

// Reverse by Recursion :

node* reverse_recursion(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* new_head=reverse_recursion(head->next);
    head->next->next=head;
    head->next= NULL;
    return new_head;
}

int main()
{
    node *head = NULL;
    int i;
    for (i = 1; i <= 10; i++)
    {
        insert_AtTail(head, i);
    }
    display(head);
    node *new_head = reverse(head);
    display(new_head);

    new_head= reverse_recursion(new_head);
    display(new_head);
    return 0;
}