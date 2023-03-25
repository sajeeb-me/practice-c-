#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N];

void dfs(int node)
{
    visited[node] = 1;

    for(int adj_node : adj_list[node])
        if(!visited[adj_node]) dfs(adj_node);
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

    int count = 0;
    for(int i=0; i<nodes; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
