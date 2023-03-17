#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 ;
int visited[N];
vector<int>adj_list[N];

bool bfs(int node, int target)
{
    queue<int> q;
    visited[node] = 1   ;
    q.push(node);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        if(head == target)
            return true;

//        cout << head << "\n";
        for(int adj_node : adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
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
    bool connected = bfs(start, target);
    if (connected) {
        cout << "Nodes " << start << " and " << target << " are connected.\n";
    } else {
        cout << "Nodes " << start << " and " << target << " are not connected.\n";
    }

    return 0;
}
