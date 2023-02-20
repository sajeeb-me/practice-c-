#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pt;
    pt.push(5);
    pt.push(7);
    pt.push(10);
    pt.push(1);
    pt.push(2);

    while(pt.size())
    {
        cout << pt.top() << " ";
        pt.pop();
    }

    return 0;
}
