#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e6+5;

int coin[N], dp[N];

int main()
{
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> coin[i];

    dp[0] = 1;

    for(int target=1; target<=x; target++)
        for(int j=0; j<n; j++)
            if(target-coin[j] >= 0)
                dp[target] = (dp[target] + dp[target - coin[j]]) % MOD;

    cout << dp[x] << "\n";

    return 0;
}
