#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back(5);
    d.push_back(15);
    d.push_back(25);
    d.push_back(20);
    d.push_back(30);

    cout << "size: " << d.size() << "\n";

    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";

    d.pop_front();
    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";

    d.pop_back();
    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";

    cout << "size: " << d.size() << "\n";

    return 0;
}

