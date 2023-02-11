#include<bits/stdc++.h>
using namespace std;
void print(list<int> l)
{
    auto a = l.begin();
    while (a != l.end())
    {
        cout << *a << " ";
        a++;
    }
    cout << "\n";
}
void deleteValue(list<int>&l, int val)
{
    auto a = l.begin();
    while (a != l.end())
    {
        if(*a == val)
        {
            l.erase(a);
            break;
        }
        a++;
    }
}
int main()
{
    list<int> l = {7,3,8,4,5,4};
    int val;
    val = 4;
    print(l);

    deleteValue(l, val);
    print(l);

    return 0;
}
