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

int main()
{
    node *n = new node(5);
    cout << n->value << " " << n->next;

    return 0;
}