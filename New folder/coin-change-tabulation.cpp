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
            for(int target=0; target<=K; target++)
                dp[i][target] = 0;

        dp[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int target=0; target<=K; target++)
            {
                dp[i][target] = dp[i-1][target];

                for(int j=1; j<=limit[i]; j++)
                {
                    if(target < j*coin[i]) break;
                    int ret = dp[i-1][target - j*coin[i]];
                    dp[i][target] = (dp[i][target] + ret) % MOD;
                }
            }
        }

        cout << "Case " << ++tst << ": " << dp[n][K] << "\n";
    }

    return 0;
}
