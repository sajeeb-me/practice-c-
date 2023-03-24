#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
vector<int> color(N, -1);

bool bfs(int node)
{
    queue<int>q;
    q.push(node);
    color[node] = 0;

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        for(int adj_node : adj_list[head])
        {
            if(color[adj_node] == -1)
            {
                color[adj_node] = 1 - color[head];
                q.push(adj_node);
            }
            else if(color[adj_node] == color[head]) return false;
        }
    }
    return true;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
    {
        int n, m;
        cin >> n >> m;
        adj_list[n].push_back(m);
        adj_list[m].push_back(n);
    }

    bool is_bipartite = true;

    for(int i=0; i<nodes; i++)
    {
        if(color[i] == -1)
        {
            bool ok = bfs(i);
            if(!ok)
            {
                is_bipartite = false;
                break;
            }
        }
    }

    cout << (is_bipartite ? "YES" : "NO");

    return 0;
}
