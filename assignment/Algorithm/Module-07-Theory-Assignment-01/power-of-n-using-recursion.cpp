#include<bits/stdc++.h>
using namespace std;

int powerOfM(int n, int m)
{
    if(m == 0)
        return 1;
    return n*powerOfM(n, m-1);
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << powerOfM(n, m) << "\n";

    return 0;
}
