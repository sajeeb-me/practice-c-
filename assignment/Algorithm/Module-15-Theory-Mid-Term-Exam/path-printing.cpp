#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
char maze[N][N];
int visited[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'U', 'D'};
vector<char> path;

bool got_boundary(int x, int y)
{
    return (x == 1 || x == n || y == 1 || y == m);
}

bool is_valid(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m && maze[x][y] != '#' && !visited[x][y]);
}

bool dfs(int x, int y)
{
    visited[x][y] = 1;
    if (got_boundary(x, y)) return true;

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (is_valid(new_x, new_y))
        {
            path.push_back(dir[i]);
            if (dfs(new_x, new_y)) return true;
            path.pop_back();
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    pair<int,int>src;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'A')
            {
                src.first = i;
                src.second = j;
            }
        }
    }

    bool possible = dfs(src.first, src.second);

    if (possible)
    {
        cout << "YES\n" << path.size() << "\n";
        for(int i=0; i<path.size(); i++) cout << path[i];
    }
    else cout << "NO\n";
    return 0;
}
