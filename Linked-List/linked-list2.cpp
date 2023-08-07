
// Insertion At End of a singly Linked-List :

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

void insert_AtEnd(node *&head, int value)
{
    node *new_node = new node(value);
    if(head==NULL){
        head=new_node;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(node *&head)
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
    insert_AtEnd(head, 2);
    display(head);
    insert_AtEnd(head, 4);
    display(head);
    insert_AtEnd(head, 6);
    display(head);
    insert_AtEnd(head, 8);
    display(head);
    insert_AtEnd(head, 10);
    display(head);
    return 0;
}
