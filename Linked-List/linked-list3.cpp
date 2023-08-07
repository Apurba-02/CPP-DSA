
// Insertion At Arbitary position of a singly Linked-List :

// Time-Complexcity-> O(N)

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

void insert_AtPosition(node *&head, int value, int pos)
{

    if (pos == 0)
    {
        insert_AtHead(head, value);
    }

    node *new_node = new node(value);
    node *temp = head;
    int current_pos = 0;
    while (current_pos != pos - 1)
    {
        temp = temp->next;
        current_pos++;
    }

    new_node->next = temp->next;
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

int main()
{
    node *head = NULL;
    insert_AtHead(head, 2);
    display(head);
    insert_AtHead(head, 4);
    display(head);
    insert_AtHead(head, 6);
    display(head);
    insert_AtHead(head, 8);
    display(head);
    insert_AtPosition(head, 10, 2);
    display(head);
    return 0;
}