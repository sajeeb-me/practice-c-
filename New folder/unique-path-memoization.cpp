#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];

int unique_path(int row, int col)
{
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];

    int ans = 0;
    if(row > 0) ans += unique_path(row-1, col);
    if(col > 0) ans += unique_path(row, col-1);

    dp[row][col] = ans;
    return ans;
}


int main()
{
    int row, col;
    cin >> row >> col;

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            dp[i][j] = -1;

    cout << unique_path(row-1, col-1) << "\n";

    return 0;
}
