#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next;
    bool visited;

    node(int data)
    {
        value = data;
        next = NULL;
        visited = false;
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


void delete_kthNode_end(node *&head, int k)
{
    node *ptr1 = head;
    node *ptr2 = head;
    int counter = 0;
    while (counter != k)
    {
        ptr1 = ptr1->next;
        counter++;
    }

    while (ptr1->next != NULL)
    {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    node *temp = ptr2->next;
    ptr2->next = ptr2->next->next;
    free(temp);
}

int main()
{
    node *head = NULL;
    insert_AtTail(head, 2);
    insert_AtTail(head, 3);
    insert_AtTail(head, 7);
    insert_AtTail(head, 2);
    insert_AtTail(head, 5);
    insert_AtTail(head, 8);
    display(head);
    delete_kthNode_end(head, 2);
    display(head);
    return 0;
}