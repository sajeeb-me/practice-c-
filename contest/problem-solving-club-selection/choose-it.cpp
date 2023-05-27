#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int dp[N][N];
vector<int> chocolates(N);
vector<int> weight(N);

int maximumNum(int n, int k)
{
    if(n==0 || k==0) return 0;
    if (dp[n][k] != -1) return dp[n][k];

    int maxNum;
    if(weight[n-1] > k)
        maxNum = maximumNum(n-1, k);
    else
        maxNum = max(chocolates[n-1] + maximumNum(n, k-weight[n-1]), maximumNum(n-1, k));

    dp[n][k] = maxNum;
    return maxNum;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=k; j++)
            dp[i][j] = -1;

    for(int i=0; i<n; i++) cin >> chocolates[i];
    for(int i=0; i<n; i++) cin >> weight[i];

    cout << maximumNum(n, k) << "\n";

    return 0;
}
