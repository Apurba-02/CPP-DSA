
// Delete the alternate elements of a linked-list :

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

void insert_AtHead(node *&head, int value)
{
    node *new_node = new node(value);
    new_node->next = head;
    head = new_node;
}

void delete_alternate(node *&head)
{
    node *temp;
    node *current_position = head;
    while (current_position != NULL  && current_position->next !=NULL)
    {
        temp=current_position->next ;
        current_position->next = current_position->next->next;
        free(temp);
        current_position = current_position->next;
    }
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

int main()
{
    node *head = NULL;
    int i;
    for (i = 9; i >= 1; i--)
    {
        insert_AtHead(head, i);
    }
    display(head);
    delete_alternate(head);
    display(head);
    return 0;
}