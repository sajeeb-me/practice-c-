#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj_list[N];
int visited[N];

bool detect_cycle(int src, int parent)
{
    visited[src] = 1;
    for(int adj_node : adj_list[src])
    {
        if(visited[adj_node] == 0)
        {
            bool got_cycle = detect_cycle(adj_node, src);
            if(got_cycle) return true;
        }
        else if(adj_node != parent) return true;
    }
    return false;
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

    bool cycle_exist = false;
    for(int i=1; i<=nodes; i++)
    {
        if(visited[i] == 0)
        {
            bool got_cycle = detect_cycle(i, -1);
            if(got_cycle)
            {
                cycle_exist = true;
                break;
            }
        }
    }

    cout << (cycle_exist ? "Cycle Exist" : "No Cycle");

    return 0;
}
