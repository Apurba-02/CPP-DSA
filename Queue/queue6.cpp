
// Implementation of circular queue using array :

#include <iostream>
#include <vector>
using namespace std;

class circular_queue
{
    vector<int> v;
    int front;
    int back;
    int current_sze;
    int total_size;

public:
    circular_queue(int c)
    {
        v.resize(c);
        front = 0;
        back = c - 1;
        current_sze = 0;
        total_size = c;
    }

    void enqueqe(int value)
    {
        if (is_full())
        {
            return;
        }
        back = (back + 1) % total_size;
        v[back] = value;
        current_sze++;
    }

    void dequeue()
    {
        if (is_empty())
        {
            return;
        }
        front = (front + 1) % total_size;
        current_sze--;
    }
    int get_front()
    {
        return v[front];
    }

    bool is_empty()
    {
        return current_sze == 0;
    }

    bool is_full()
    {
        return current_sze == total_size;
    }
};

int main()
{
    circular_queue cq(3);
    cout << cq.is_empty() << endl;
    cq.enqueqe(5);
    cq.enqueqe(10);
    cq.enqueqe(15);
    cq.dequeue();
    cq.enqueqe(20);
    while (!cq.is_empty())
    {
        cout << cq.get_front() << endl;
        cq.dequeue();
    }
    return 0;
}
