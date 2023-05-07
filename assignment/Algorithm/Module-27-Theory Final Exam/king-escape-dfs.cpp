#include <iostream>
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

void dfs(int a, int b) {
    visited[a][b] = true;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            int x = a+i, y = b+j;
            if (check(x, y)) dfs(x, y);
        }
    }
}

int main() {
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    dfs(bx, by);
    cout << (visited[cx][cy] ? "YES" : "NO" )<< endl;
    return 0;
}
