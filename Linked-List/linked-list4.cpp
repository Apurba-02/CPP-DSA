
// Updatation At Arbitary position of a singly Linked-List :

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

void update_atPosition(node* &head , int value, int pos ){
    int current_position=0 ;
    node* temp = head ;
    while(current_position != pos){
        temp= temp->next;
        current_position++;
    }
    temp->value= value;
}

void display(node* head){
    node* temp = head ;
    while(temp != NULL){
        cout<<temp->value<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL ;
    insert_AtHead(head, 2);
    display(head);
    insert_AtHead(head, 4);
    display(head);
    insert_AtHead(head, 6);
    display(head);
    insert_AtHead(head, 8);
    display(head);
    update_atPosition(head, 10, 2);
    display(head);
    return 0;
}
