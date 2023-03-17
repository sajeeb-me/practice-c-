#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 ;
int visited[N];
vector<int>adj_list[N];

bool dfs(int node, int target)
{
    if(node == target)
        return true;

    cout << node << " ";
    visited[node] = 1;


    for(int adj_node : adj_list[node])
    {
        if(!visited[adj_node])
        {
            if(dfs(adj_node, target))
                return true;
        }
    }
    return false;
}

int main()
{

    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++)   // loop over the number of edges
    {
        int u, v;
        cin >> u >> v; // there exists an edge between node u and v
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int start = 2, target = 6;
    bool connected = dfs(start, target);
    if (connected)
    {
        cout << "Nodes " << start << " and " << target << " are connected.\n";
    }
    else
    {
        cout << "Nodes " << start << " and " << target << " are not connected.\n";
    }

    return 0;
}

