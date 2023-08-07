
// Array implementation of Queues :

#include <iostream>
#include <vector>
using namespace std;

class queue
{
    int front;
    int back;
    vector<int> v;

public:
    queue()
    {
        front = -1;
        back = -1;
    }

    void enqueqe(int value)
    {

        if (back == 0)
        {
            front = 0;
        }
        v.push_back(value);
        back++;
    }

    void dequeue()
    {
        if (front == back)
        {
            back = -1;
            front = -1;
            v.clear();
        }
        else
        {
            front++;
        }
    }

    int get_front(){
        if(front==-1){
            return INT64_MIN;
        }
        else{
            return v[front];
        }
    }

    int get_size(){
        if(front==-1){
            return 0;
        }
        return back-front+1;
    }

    bool is_empty(){
        return front==-1;
    }
};

int main()
{
    queue qu;
    cout << qu.get_size() << endl;
    cout << qu.is_empty() << endl;
    qu.enqueqe(5);
    qu.enqueqe(10);
    qu.enqueqe(15);
    qu.dequeue();
    qu.enqueqe(20);
    cout << qu.get_size() << endl;
    cout << qu.get_front() << endl;
    while (!qu.is_empty())
    {
        cout << qu.get_front() << endl;
        qu.dequeue();
    }
    return 0;
}

