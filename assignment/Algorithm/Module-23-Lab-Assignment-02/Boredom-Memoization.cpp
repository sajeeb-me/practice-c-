#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long countNum[N],dp[N];

long long points(int n)
{
    if(n < 0) return 0;
    if(dp[n]) return dp[n];
    dp[n] = max(points(n-1), points(n-2)+n*countNum[n]);
    return dp[n];
}

int main()
{
    long long n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int j;
        cin>>j;
        countNum[j]++;
    }

    cout << points(n) << "\n";

    return 0;
}
