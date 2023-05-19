#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

int n, m;
string s, t;
string dp[N][N];

string LCS(int i, int j)
{
    if(i==n || j==m) return "";
    if(dp[i][j] != "") return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = s[i] + LCS(i+1, j+1);

    return dp[i][j] = (LCS(i+1, j).size() > LCS(i, j+1).size() ? LCS(i+1, j) : LCS(i, j+1));
}

int main()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            dp[i][j] = "";

    cout << LCS(0, 0) << "\n";

    return 0;
}
