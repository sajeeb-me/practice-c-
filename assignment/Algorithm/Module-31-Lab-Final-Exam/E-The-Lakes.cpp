#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int a[N][N];
bool visited[N][N];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool isSafeAndNotVisited(int a, int b)
{
    if(!visited[a][b] && a>=0 && a<n && b>=0 && b<m) return true;
    return false;
}

int dfs(int i, int j)
{
    visited[i][j] = true;
    int ans = a[i][j];

    for(int k=0; k<4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if(isSafeAndNotVisited(x, y) && a[x][y] != 0)
            ans += dfs(x, y);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin >> a[i][j];
                visited[i][j] = false;
            }

        int vol = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j] != 0 && !visited[i][j])
                {
                    int vol1 = dfs(i, j);
                    vol = max(vol, vol1);
                }
            }
        }
        cout << vol << "\n";
    }

    return 0;
}
