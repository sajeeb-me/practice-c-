#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

int n, m;
string s1, s2;
int dp[N][N];

int LCM(int i, int j)
{
    if(i==n || j==m) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j])
    {
        int ans = 1 + LCM(i+1, j+1);
        dp[i][j] = ans;
        return ans;
    }
    int ans = max(LCM(i+1, j), LCM(i, j+1));
    dp[i][j] = ans;
    return ans;
}

int main()
{
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            dp[i][j] = -1;

    cout << LCM(0, 0) << "\n";

    return 0;
}
