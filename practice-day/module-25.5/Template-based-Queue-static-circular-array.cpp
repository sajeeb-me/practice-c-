#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 10;

template<class T>
class Queue
{
public:
    T a[MAX_SIZE];
    int l, r, sz;

    Queue()
    {
        l = 0;
        r = -1;
        sz = 0;
    }
    void enqueue(T value)
    {
        if(sz == MAX_SIZE)
        {
            cout << "Queue is full!\n";
            return;
        }
        r++;
        if(r == MAX_SIZE)
            r = 0;
        a[r] = value;
        sz++;
    }
    void dequeue()
    {
        if(sz == 0)
        {
            cout << "Queue is empty!\n";
            return;
        }
        l++;
        if(l == MAX_SIZE)
            l = 0;
        sz--;
    }
    T front()
    {
        if(sz == 0)
        {
            cout << "Queue is empty!\n";
            T a;
            return a;
        }
        return a[l];
    }
    int size()
    {
        return sz;
    }
};

int main()
{
    Queue<char> q;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');

    cout << "Size: " << q.size() << "\n";
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();    cout << q.front() << "\n";
    q.dequeue();
    cout << "Size: " << q.size() << "\n";

    return 0;
}
