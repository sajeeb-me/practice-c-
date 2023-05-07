#include <iostream>
#include <queue>
using namespace std;

const int N = 1005;
int n, ax, ay, bx, by, cx, cy;
bool visited[N][N];

bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n) return false;
    if (visited[x][y]) return false;
    if (abs(x - ax) == abs(y - ay) || x == ax || y == ay ) return false;
    return true;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({bx, by});
    visited[bx][by] = true;
    while (!q.empty())
    {
        auto position = q.front();
        q.pop();
        for (int i=-1; i<=1; i++)
        {
            for (int j=-1; j<=1; j++)
            {
                int x = position.first+i, y = position.second+j;
                if (check(x, y))
                {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }
}

int main()
{
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    bfs();
    cout << (visited[cx][cy] ? "YES" : "NO" )<< endl;
    return 0;
}
