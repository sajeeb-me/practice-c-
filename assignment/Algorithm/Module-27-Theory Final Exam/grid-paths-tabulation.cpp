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
        dp[0][0] = 1;
        if(grid[0][0] == '*') return 0;
        for (int i = 0; i < n; i++)
        {
            for (int j=0; j < n; j++)
            {
                if ((i==0 && j==0) || grid[i][j] == '*') continue;

                if (i==0) dp[i][j] = dp[i][j-1];
                else if (j==0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MODULO;
            }
        }
        return dp[n - 1][n - 1];
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
/*
4
....
.*..
...*
*...
*/
