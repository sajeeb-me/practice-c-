#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

int n, m;
string s1, s2;
int dp[N][N];

int main()
{
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();

    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=m; j++) dp[0][j] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}

