#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N], level[N];

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    visited[node] = 1;
    level[node] = 0;

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        for(int adj_node : adj_list[head])
        {
            if(!visited[adj_node])
            {
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
        int n, m;
        cin >> n >> m;
        adj_list[n].push_back(m);
        adj_list[m].push_back(n);
    }

    int src_node = 0;
    bfs(src_node);

    for(int i=0; i<nodes; i++)
        cout << "node " << i << " -> level: " << level[i] << "\n";

    return 0;
}



/*
sample input:
6 7
0 1
0 3
0 4
1 5
1 2
2 4
4 5
*/
