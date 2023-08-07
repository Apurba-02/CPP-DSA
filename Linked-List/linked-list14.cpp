
// Find the intersection of two singly lined-list :

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

int find_intersection(node *head1, node *head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;

    while (ptr1 != NULL)
    {
        ptr1->visited= true;
        ptr1=ptr1->next;
    }

    while(ptr2 !=NULL){
        if(ptr2->visited==true){
            return ptr2->value;
        }
        else{
            ptr2->visited= true;
        }
        ptr2=ptr2->next;
    }
}

int main(){
    node* head1 =NULL;
    node* head2 = NULL;

    insert_AtTail(head1 ,3);
    insert_AtTail(head1 ,7);
    insert_AtTail(head1 ,2);
    insert_AtTail(head1 ,5);
    insert_AtTail(head1 ,8);
    display(head1);
    insert_AtTail(head2 ,45);
    insert_AtTail(head2 ,67);
    insert_AtTail(head2 ,1);
    head2->next->next->next= head1->next;
    insert_AtTail(head2 ,4);
    display(head2);
    cout<<find_intersection(head1, head2);
    return 0;
}