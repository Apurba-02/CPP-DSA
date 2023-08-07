
// Check two linked-list is equal or not :

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
        temp= temp->next;
    }
    cout << "NULL" << endl;
}

bool check_equal(node *head1, node *head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->value != ptr2->value)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return (ptr1 == NULL && ptr2== NULL);
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;

    insert_AtTail(head1 , 2);
    insert_AtTail(head1 , 3);
    insert_AtTail(head1 , 4);
    display(head1);
    insert_AtTail(head2 , 2);
    insert_AtTail(head2 , 3);
    insert_AtTail(head2 , 4);
    display(head2);
    cout<<check_equal(head1 , head2);
    return 0;
}
