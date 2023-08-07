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

node* swap_Alternate(node* &head){

    if (head== NULL || head->next==NULL){
        return head;
    }
    node* second_node = head->next;
    head->next = swap_Alternate(second_node->next);
    second_node->next=head;
     return second_node;
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
    head = swap_Alternate(head);
    display(head);
    return 0;
}
