#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

vector<vector<int>>adj_list(N);
vector<bool>visited(N, false);

bool bfs(int x, int y, int k)
{
    queue<pair<int, int>> q;
    q.push({x, k});

    visited[x] = true;

    while(!q.empty())
    {
        int current = q.front().first;
        int remaining = q.front().second;
        q.pop();

        if(current == y && remaining >= 0) return true;

        for(auto adj_node : adj_list[current])
        {
            if(!visited[adj_node] && remaining > 0)
            {
                q.push({adj_node, remaining-1});
                visited[adj_node] = true;
            }
        }
    }
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int x, y, k;
    cin >> x >> y >> k;

    bool canReunited = bfs(x, y, k*2);

    cout << (canReunited ? "YES\n" : "NO\n");

    return 0;
}
