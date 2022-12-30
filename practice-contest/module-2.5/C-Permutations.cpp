#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n<4 && n>1)
        cout << "NO SOLUTION" << "\n";
    else
    {
        for(int i=n-1; i>=1; i-=2)
            cout << i << " ";
        for(int i=n; i>=1; i-=2)
            cout << i << " ";
    }

    return 0;
}
