
// Reverse a stack :

#include<iostream>
#include<stack>
using namespace std;

void  reverse(stack<int> &input){
    stack<int> temp1 , temp2;
    while(not input.empty()){
        int current=input.top();
        temp1.push(current);
        input.pop();
    }

    while(not temp1.empty()){
        int current=temp1.top();
        temp2.push(current);
        temp1.pop();
    }

    while(not temp2.empty()){
        int current=temp2.top();
        input.push(current);
        temp2.pop();
    }
}

int main(){
    stack<int> input_stack;
     input_stack.push(1);
    input_stack.push(2);
    input_stack.push(3);
    input_stack.push(4);
    input_stack.push(5);
    reverse(input_stack);
    while (not input_stack.empty())
    {
        int current = input_stack.top();
        cout << current << endl;
        input_stack.pop();
    }
    return 0;
}