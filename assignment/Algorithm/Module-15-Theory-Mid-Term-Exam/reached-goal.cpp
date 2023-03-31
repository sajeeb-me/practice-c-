#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj_list[N];
int visited[N];

void dfs(int src)
{
    visited[src] = 1;
    for(int adj_node : adj_list[src])
        if(!visited[adj_node]) dfs(adj_node);
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1);
    cout << (visited[nodes] ? "YES" : "NO");

    return 0;
}
