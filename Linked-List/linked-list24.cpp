
//Insertion at the end and arbitary position of a dubly linked list

#include <iostream>
#include <ostream>
using namespace std;
class node
{
public:
    int value;
    node *next;
    node *prev;

    node(int data)
    {
        value = data;
        next = NULL;
        prev = NULL;
    }
};

class dubly_linkedlist
{
public:
    node *head;
    node *tail;

    dubly_linkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_atEnd(int value){
        node* new_node =new node(value);
        if(tail==NULL){
            tail=new_node;
            head=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        
    }

    void insert_atArbitary(int k , int value){
        node* temp= head;
        node* new_node = new node(value);
    
        int counter =0;
        while(counter !=k-1){
            temp =temp->next;
            counter++;
        }
        new_node->next=temp->next;
        temp->next->prev=new_node;
        temp->next=new_node;
        new_node->prev=temp;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
           std:: cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << endl;
    }

};

int main(){
    dubly_linkedlist dll;
    dll.insert_atEnd(5);
    dll.insert_atEnd(15);
    dll.insert_atEnd(25);
    dll.insert_atEnd(35);
    dll.insert_atEnd(45);
    dll.display();
    dll.insert_atArbitary(3, 65);
    dll.display();
    return 0;
}
