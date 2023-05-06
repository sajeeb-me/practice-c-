#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
long long dp[N][N];
int MODULO = 1e9 + 7;

class Solution
{
public:
    long long countPaths(int n, vector<string>& grid)
    {
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                dp[i][j] = -1;

        return countNum(n-1, n-1, grid);
    }

    long long countNum(int i, int j, vector<string>& grid)
    {
        if (i<0 || j<0 || grid[i][j]=='*') return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        long long ans = (countNum(i-1, j, grid) + countNum(i, j-1, grid)) % MODULO;
        dp[i][j] = ans;
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    Solution s;
    cout << s.countPaths(n, grid) << endl;

    return 0;
}
