
// Delete the dublicate elements from a linked-list if the list is shorted :

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

void delete_dublicate(node *&head)
{
    node *current_node = head;
    while (current_node != NULL)
    {
        while(current_node->next && current_node->value == current_node->next->value)
        {
           node* temp = current_node->next;
            current_node->next = current_node->next->next;
            free(temp);
        }
       current_node = current_node->next;
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
    insert_AtHead(head, 10);
    insert_AtHead(head, 9);
    insert_AtHead(head, 9);
    insert_AtHead(head, 9);
    insert_AtHead(head, 7);
    insert_AtHead(head, 6);
    insert_AtHead(head, 6);
    insert_AtHead(head, 2);
    display(head);
    delete_dublicate(head);
    display(head);
    return 0;
}