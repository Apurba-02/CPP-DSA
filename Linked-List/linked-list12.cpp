
// Reversing K nodes at a time :


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

void insert_atTail(node *&head, int value)
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

node *reverse_k(node *&head, int k)
{
    int length =0;
    node* temp = head;
    while(temp!=NULL){
        length++;
        temp=temp->next; 
    }
    free(temp);
    node *prev = NULL;
    node *current = head; 
    int counter = 0;
    
    while (current != NULL && counter != k)
    {
        node *then = current->next;
        current->next= prev;
        prev = current;
        current = then;
        counter++;
    }
    length=length-k;

    if (current != NULL && length>=k)
    {
        node *new_head = reverse_k(current, k);
        head->next = new_head;
    }
    else {
        temp= prev;
        while(temp->next != NULL){
            temp =temp->next;
        }
        temp->next=current;
    }
    return prev;
     
}

int main()
{
    node *head = NULL;
    insert_atTail(head , 1);
    insert_atTail(head , 2);
    insert_atTail(head , 3);
    insert_atTail(head , 4);
    insert_atTail(head , 5);
    insert_atTail(head , 6);
    display(head);
    head=reverse_k(head, 2);
    display(head);
    return 0;
}