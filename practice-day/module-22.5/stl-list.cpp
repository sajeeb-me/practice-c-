#include<bits/stdc++.h>
using namespace std;

void Print(list<int> l)
{
    list<int>::iterator it = l.begin();
    while(it != l.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << "\n";
}

int getValue(list<int>l, int index)
{
    auto it = l.begin();
    advance(it, index);
    return *it;
}

bool search(list<int>l, int value)
{
    return find(l.begin(), l.end(), value) != l.end();
}

void delteZero(list<int>&l)
{
    l.remove(0);
}

int main()
{
    list<int> l;
    l.push_front(3);
    l.push_front(0);
    l.push_front(2);
    l.push_front(0);
    l.push_front(6);
    l.push_front(0);
    l.push_front(5);
    Print(l);

    cout << getValue(l, 4) << "\n";
    cout << (search(l, 6) ? "true" : "false") << "\n";

    delteZero(l);
    Print(l);

    return 0;
}
