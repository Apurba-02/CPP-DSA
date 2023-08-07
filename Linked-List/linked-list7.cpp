
//  Deletion at arbitary position of a singly Linked-List :

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

void delete_arbitary(node *&head, int pos)
{
    node *temp = head;
    int current_pos = 0;
    if (pos == 0)
    {
        head = head->next;
        free(temp);
    }

    else
    {
        node *temp1;
        while (current_pos != pos - 1)
        {
            temp = temp->next;
            current_pos++;
        }
        temp1 = temp->next;
        temp->next = temp->next->next;
        free(temp1);
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
    insert_AtHead(head, 1);
    display(head);
    insert_AtHead(head, 4);
    display(head);
    insert_AtHead(head, 6);
    display(head);
    insert_AtHead(head, 8);
    display(head);
    delete_arbitary(head, 1);
    display(head);
    return 0;
}