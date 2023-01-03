#include<bits/stdc++.h>
using namespace std;

class Array
{
private:
    int* arr;
    int cap;
    int sz;

    void Increase_size()
    {
        cap = cap*2;
        int* tmp = new int[cap];
        for(int i=0; i<sz; i++)
            tmp[i] = arr[i];

        delete[] arr;
        arr = tmp;
    }

public:
    Array()
    {
        arr = new int[1];
        cap = 1;
        sz = 0;
    }
    void Push_back(int x)
    {
        if(cap==sz)
            Increase_size();
        arr[sz]=x;
        sz++;
    }
    void Print()
    {
        for(int i=0; i<sz; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    int getSize()
    {
        return sz;
    }
    int getElement(int idx)
    {
        if(idx>sz)
        {
            cout << "Error " << idx << " is out of bound! \n";
            return -1;
        }
        return arr[idx];
    }
    void Insert(int pos, int x)
    {
        if(cap==sz)
            Increase_size();
        for(int i=sz-1; i>=pos; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[pos]=x;
        sz++;
    }
    void Pop_back()
    {
        if(sz==0)
        {
            cout << "Current size is 0. \n";
            return;
        }
        sz--;
    }
    void Remove(int x)
    {
        if(x>sz)
        {
            cout << "Size no exist.\n";
            return;
        }
        for(int i=x+1; i<sz; i++)
        {
            arr[i-1] = arr[i];
        }
        sz--;
    }
};

int main()
{
    Array a;

    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(50);
    a.Push_back(60);
    a.Push_back(40);
    a.Insert(2, 15);
    a.Insert(4, 25);

    a.Print();

    a.Pop_back();
    a.Print();

    a.Pop_back();
    a.Print();

    a.Remove(2);
    a.Print();

    cout << "size: " << a.getSize() << "\n";

    for(int i=0; i<a.getSize(); i++)
    {
        cout << a.getElement(i) << "\n";
    }
    return 0;
}
