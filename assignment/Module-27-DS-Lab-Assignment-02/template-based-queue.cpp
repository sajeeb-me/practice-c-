#include<bits/stdc++.h>
using namespace std;

template<class T>
class Queue
{
public:
    T* arr;
    int l, r, sz, arr_cap;

    Queue()
    {
        arr_cap = 1;
        arr = new T[arr_cap];
        l = 0;
        r = -1;
        sz = 0;
    }
    void remove_circular()
    {
        if(l>r)
        {
            T* tmp = new T[arr_cap];
            int idx = 0;
            for(int i=l; i<arr_cap; i++)
            {
                tmp[idx] = arr[i];
                idx++;
            }
            for(int i=0; i<=r; i++)
            {
                tmp[idx] = arr[i];
                idx++;
            }
            swap(tmp, arr);
            delete[] tmp;
        }
    }
    void increase_size()
    {
        remove_circular();

        T* tmp = new T[arr_cap*2];
        for(int i=0; i<arr_cap; i++)
            tmp[i] = arr[i];
        swap(tmp, arr);
        delete[] tmp;
        arr_cap *= 2;
    }
    void enqueue(T value)
    {
        if(sz == arr_cap)
            increase_size();

        r++;
        if(r == arr_cap)
            r = 0;
        arr[r] = value;
        sz++;
    }
    void dequeue()
    {
        if(sz == 0)
        {
            cout << "Queue if empty!\n";
            return;
        }
        l++;
        if(l == arr_cap)
            l = 0;
        sz--;
    }
    T front()
    {
        if(sz == 0)
        {
            cout << "Queue if empty!\n";
            T a;
            return a;
        }
        return arr[l];
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << q.front() << "\n";

    q.dequeue();
    cout << q.front() << "\n";    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();

    return 0;
}
