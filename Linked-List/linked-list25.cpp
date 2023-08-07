
// Deletion at head, tail and arbitary position of a dubly linked-list :

#include <iostream>
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

    void inserrt_AtTail(int value)
    {
        node *new_node = new node(value);
        if (tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << endl;
    }


    void delete_head(){
        node* temp=head;
        head= head->next;
        head->prev=NULL;
        free(temp); 
    }

    void delete_tail(){
        node*temp = tail ;
        tail= tail->prev;
        tail->next=NULL;
        free(temp);
    }


    void delete_Arbitary(int k){
        node* temp =head;
        int counter=0;
        while(counter != k){
            temp =temp->next;
            counter++;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }

};

int main(){
    dubly_linkedlist dll;
    dll.inserrt_AtTail(3);
    dll.inserrt_AtTail(5);
    dll.inserrt_AtTail(7);
    dll.inserrt_AtTail(9);
    dll.inserrt_AtTail(55);
    dll.inserrt_AtTail(15);
    dll.inserrt_AtTail(25);
    dll.inserrt_AtTail(35);
    dll.inserrt_AtTail(45);
    dll.display();
    dll.delete_head();
    dll.display();
    dll.delete_tail();
    dll.display();
    dll.delete_Arbitary(2);
    dll.display();
    return 0;
}