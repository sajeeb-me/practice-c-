#include<bits/stdc++.h>
using namespace std;

const int N = 10e3;

int h[N], dp[N];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> h[i];
        dp[i] = -1;
    }

    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
        int ans1 = dp[i-1]+abs(h[i]-h[i-1]);
        if(n==2)
        {
            dp[i] = ans1;
            continue;
        }
        int ans2 = dp[i-2]+abs(h[i]-h[i-2]);

        dp[i] = min(ans1, ans2);
    }

    cout << dp[n] << "\n";

    return 0;
}

