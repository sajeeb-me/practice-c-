#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

class Solution
{
public:

    int longestPalindromeSubseq (string s)
    {
        int n = s.size();

        memset(dp, -1, sizeof(dp));

        return helper(s, 0, n-1);
    }

    int helper(string s, int l, int r)
    {
        if(l > r) return 0;
        if(l == r) return 1;
        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] == s[r])
            return dp[l][r] = 2 + helper(s, l+1, r-1);
        else
            return dp[l][r] = max(helper(s, l+1, r), helper(s, l, r-1));
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << "\n";

    return 0;
}
