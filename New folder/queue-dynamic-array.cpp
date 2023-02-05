#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int* a;
    int l, r, sz, array_cap;

    Queue()
    {
        array_cap = 1;
        a = new int[array_cap];
        l = 0;
        r = -1;
        sz = 0;
    }

    void remove_circular()
    {
        if(l>r)
        {
            int* tmp = new int[array_cap];
            int idx = 0;
            for(int i=l; i<array_cap; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            for(int i=0; i<=r; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            swap(tmp, a);
            delete[] tmp;
        }
    }

    void increase_size()
    {
        remove_circular();

        int* tmp = new int[array_cap*2];
        for(int i=0; i<array_cap; i++)
            tmp[i] = a[i];
        swap(tmp, a);
        array_cap *= 2;
        delete[] tmp;
    }

    void enqueue(int val)
    {
        if(sz == array_cap)
        {
            increase_size();
        }
        r++;
        if(r == array_cap)
            r = 0;
        a[r] = val;
        sz++;
    }

    void dequeue()
    {
        if(sz == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        l++;
        if(l == array_cap)
            l = 0;
        sz--;
    }

    int front()
    {
        if(sz == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return a[l];
    }

    int size()
    {
        return r-l+1;
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout << "Q size: " << q.size() << "\n";
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << "Q size: " << q.size() << "\n";

    return 0;
}
