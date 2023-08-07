
// Group nodes with odd and even indices together and returen the reordered list :

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

node *odd_even(node *&head)
{
    node *odd = head;
    node *even_head = head->next;
    node *even = even_head;

    if (head==NULL){
        return head;
    }

    while (even && even->next)
    {
        odd->next= odd->next->next;
        even->next=even->next->next;
        odd= odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return head;
}

int main()
{
    node *head = NULL;
    insert_AtTail(head, 1);
    insert_AtTail(head, 2);
    insert_AtTail(head, 3);
    insert_AtTail(head, 4);
    insert_AtTail(head, 5);
    insert_AtTail(head, 6);
    display(head);
    head = odd_even(head);
    display(head);
    return 0;
}