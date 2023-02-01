#include<bits/stdc++.h>
using namespace std;

void print(list<int> l)
{
//    auto a = l.begin();
    list<int> ::iterator a = l.begin();
    while(a != l.end())
    {
        cout << *a << " ";
        a++;
    }
    cout << "\n";
}

void Insert(list<int>&l, int index, int value)
{
    auto it = l.begin();
    advance(it, index);
    l.insert(it, value);
}
void Delete(list<int>&l, int index)
{
    auto it = l.begin();
    advance(it, index);
    l.erase(it);
}

int main()
{
    list<int> l;
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    print(l);

    l.push_back(40);
    l.push_back(50);
    print(l);

    l.pop_back();
    print(l);

    l.pop_front();
    print(l);

    Insert(l,1,120);
    print(l);

    Delete(l,2);
    print(l);

    cout << l.size() << "\n";

    return 0;
}
