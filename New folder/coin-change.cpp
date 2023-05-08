#include<bits/stdc++.h>
using namespace std;

const int N = 60;
const int M = 1001;
const int MOD = 1e8+7;

int dp[N][M];
int coin[N], limit[N];

int fun(int n, int K)
{
    if(n==0)
    {
        if(K==0) return 1;
        return 0;
    }

    if(dp[n][K] != -1) return dp[n][K];

    int ans = fun(n-1, K);

    for(int i=1; i<=limit[n]; i++)
    {
        if(K - i*coin[n] < 0) break;
        int ret = fun(n-1, K - i*coin[n]);
        ans = (ans + ret) % MOD;
    }

    dp[n][K] = ans;
    return ans;
}

int main()
{
    int t, tst = 0;
    cin >> t;

    while(t--)
    {
        int n, K;
        cin >> n >> K;

        for(int i=1; i<=n; i++) cin >> coin[i];
        for(int i=1; i<=n; i++) cin >> limit[i];

        for(int i=0; i<=n; i++)
            for(int j=0; j<=M; j++)
                dp[i][j] = -1;

        cout << "Case " << ++tst << ": " << fun(n, K) << "\n";
    }

    return 0;
}
