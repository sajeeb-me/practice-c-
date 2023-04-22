#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long countNum[N],dp[N];

int main()
{
    long long n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int j;
        cin>>j;
        countNum[j]++;
    }

    dp[0]=0;
    dp[1]=countNum[1];
    for(int i=2;i<=N;i++)
        dp[i] = max(dp[i-1] , dp[i-2]+i*countNum[i]);

    cout << dp[N-1] << "\n";
    return 0;
}
