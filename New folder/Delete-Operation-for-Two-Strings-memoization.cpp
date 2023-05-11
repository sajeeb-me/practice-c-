#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

class Solution
{
public:
    int minDistance (string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();

        memset(dp, -1, sizeof(dp));

        return n1+n2-2*helper(word1, word2, n1-1, n2-1);
    }

    int helper(string w1, string w2, int n1, int n2)
    {
        if(n1 < 0 || n2 < 0) return 0;
        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(w1[n1] == w2[n2]) return dp[n1][n2] = 1 + helper(w1, w2, n1-1, n2-1);
        else return dp[n1][n2] = max(helper(w1, w2, n1-1, n2), helper(w1, w2, n1, n2-1));
    }
};

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    Solution sol;
    cout << sol.minDistance(word1, word2) << "\n";

    return 0;
}
