#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N];

bool dfs(int node)
{
    visited[node] = 1;
    for(int adj_node : adj_list[node])
    {
        if(!visited[adj_node])
        {
            bool got_cycle = dfs(adj_node);
            if(got_cycle) return true;
        }
        else if(visited[adj_node] == 1) return true;
    }

    visited[node] = 2;
    return false;
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
    }

    bool cycle_exist = false;

    for(int i=0; i<nodes; i++)
    {
        if(!visited[i])
        {
            bool got_cycle = dfs(i);
            if(got_cycle)
            {
                cycle_exist = true;
                break;
            }
        }
    }

    cout << (cycle_exist ? "YES" : "NO");

    return 0;
}
