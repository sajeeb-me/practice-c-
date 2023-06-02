#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long l, r;
        cin >> l >> r;
        long long sum = 0;

        if(r>l)
            sum = ((r-l+1)*(l+r))/2;
        else
            sum = ((l-r+1)*(l+r))/2;

        cout << sum << "\n";
    }

    return 0;
}

