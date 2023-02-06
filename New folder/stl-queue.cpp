#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);

    cout << "Size: " << q.size() << "\n";
    cout << (q.empty() ? "Empty" : "Not empty") << "\n";
    cout << q.front() << "\n";

    q.pop();
    cout << q.front() << "\n";
    q.pop();
    cout << q.front() << "\n";
    q.pop();

    cout << "Size: " << q.size() << "\n";
    cout << (q.empty() ? "Empty" : "Not empty") << "\n";

    return 0;
}

