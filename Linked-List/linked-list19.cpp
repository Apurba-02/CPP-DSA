
// Rotate a singly linked-list by k times :

#include<iostream>
using namespace std;
class node{
    public:
    int value;
    node* next ;

    node(int data){
        value= data;
        next= NULL;
    }
};

void insert_AtTail(node* &head , int value){
    node* new_node = new node(value);
    node* temp = head;
    if( head== NULL){
        head= new_node;
        return;
    }

    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next=new_node;
}

void display(node* head){
    node* temp = head;
    while(temp !=NULL)
    {
        cout<<temp->value<<"->";
        temp =temp->next;
    }
    cout<<"NULL"<<endl;
}


node* rotate(node* &head , int k){
    int length =0;
    node* temp = head;
    while(temp->next !=nullptr){
        length++;
        temp=temp->next; 
    }
    length++;
    k= k%length;
    if(k==0){
        return head ;
    }

        int i;
        temp->next=head;
        node* temp2=head;
        for(i=1 ; i< length-k ;i++){
            temp2= temp2->next;
        }
        node* temp3 =temp2->next ;
        temp2->next =NULL;
        return temp3; 
}

int main()
{
    node *head = NULL;
    insert_AtTail(head, 2);
    insert_AtTail(head, 5);
    insert_AtTail(head, 7);
    insert_AtTail(head, 9);
    insert_AtTail(head, 6);
    insert_AtTail(head, 1);
    display(head);
    node* new_head = rotate(head , 2);
    display(new_head);
    return 0;
}