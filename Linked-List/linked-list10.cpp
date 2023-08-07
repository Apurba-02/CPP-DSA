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

void print_rev(node *head)
{
    if (head == NULL)
    {
        return;
    }

    print_rev(head->next);
    cout << head->value << " ";
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
    print_rev(head);
    
    return 0;
}
