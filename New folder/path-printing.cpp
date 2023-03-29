#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int>adj_list[N];
int visited[N], level[N], parent[N];

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    visited[node] = 1;
    level[node] = 1;
    parent[node] = -1;

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        for(int adj_node : adj_list[head])
        {
            if(!visited[adj_node])
            {
                parent[adj_node] = head;
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
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

    int src_node = 1;
    bfs(src_node);

    int des_node = nodes;

    if(!visited[des_node])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << level[des_node] << "\n";

    vector<int> path;
    int selected_node = des_node;

    while(1)
    {
        path.push_back(selected_node);
        if(selected_node == src_node) break;
        selected_node = parent[selected_node];
    }

    reverse(path.begin(), path.end());

    for(int node: path) cout << node << " ";
    cout << "\n";

    return 0;
}


/*
5 5
1 2
1 3
1 4
2 3
5 4
*/
