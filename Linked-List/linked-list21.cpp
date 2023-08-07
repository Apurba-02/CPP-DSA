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
node *find_middle(node* &head){
    node* slow= head;
    node* fast = head;

    while(fast!= NULL && fast->next !=NULL){
        slow= slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* reverse_2ndHalf(node* &head){
    node* current = find_middle(head);
    node* prev = NULL;
    while(current != NULL){

        node* then = current->next;
        current->next=prev;
        prev= current;
        current =then;
    }
    return prev;
}

node* reorder(node* &head){
    node* head1 = head;
    node* head2 = reverse_2ndHalf(head);
    
    while(head1 != head2){
        node* temp=head1->next; 
        head1->next= head2;
        head1=head2;
        head2= temp;  
    }
    return head;
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
    head = reorder(head);
    display(head);
    return 0;
}