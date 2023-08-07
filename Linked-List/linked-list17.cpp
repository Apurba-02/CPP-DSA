
// Check that a singly linked-list has a cycly or not and remove the cycle :

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

bool detect_cyclic(node* &head){
    node* fast= head;
    node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow= slow ->next;
        fast= fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void remove_cycle(node* &head){
    node* slow= head;
    node* fast= head;
    do
    {
     slow= slow->next;
     fast= fast->next->next;
    } while (slow !=fast);

    fast = head;
    while(slow->next != fast->next){
        slow= slow->next;
        fast = fast->next;
    }
    slow->next=NULL;   
}

int main()
{
    node *head= NULL;
    insert_AtTail(head, 2);
    insert_AtTail(head, 3);
    insert_AtTail(head, 7);
    insert_AtTail(head, 2);
    insert_AtTail(head, 5) ;
    insert_AtTail(head, 8);
    head->next->next->next->next->next->next = head->next->next;
    cout<<detect_cyclic(head)<<endl;
    remove_cycle(head);
    cout<<"After removing cycle: "<< endl;
    cout<<detect_cyclic(head)<<endl;
    display(head);
    return 0;
}