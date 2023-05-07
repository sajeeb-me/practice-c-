#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int>dp(n+1, -1);
        return findMinSquares(n, dp);
    }

    int findMinSquares(int n, vector<int>& dp)
    {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int minCount = INT_MAX;
        for (int i=1; i*i<=n; i++)
        {
            int countNum = findMinSquares(n-i*i, dp) + 1;
            minCount = min(minCount, countNum);
        }
        dp[n] = minCount;
        return minCount;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution s;
    cout << s.numSquares(n) << endl;

    return 0;
}
