#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    for(int i=1; i<=n; i++)
    {
        string tmp = q.front();
        cout << i << " -> " << tmp << "\n";
        q.pop();
        q.push(tmp + "0");
        q.push(tmp + "1");
    }

    return 0;
}
