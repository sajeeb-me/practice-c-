#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int nodes, edges;
vector<pair<int, int>> adj_list[N];

long long d[N];
int visited[N], parent[N];


void dijkstra(int src)
{
    for(int i=1; i<=nodes; i++) d[i]=INF;
    d[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        pair<long long, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;
        if(visited[selected_node]) continue;
        visited[selected_node] = 1;

        for(auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[selected_node] + edge_cst < d[adj_node])
            {
                d[adj_node] = d[selected_node] + edge_cst;
                parent[adj_node] = selected_node;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 4;
    dijkstra(src);

    if(visited[nodes] == 0)
    {
        cout << -1 << "\n";
        return 0;
    }

    for(int i=1; i<=nodes; i++) cout << i << "->" << d[i] << " ";

    cout << "\n";

    int current_node = nodes;
    vector<int>path;

    while(true)
    {
        path.push_back(current_node);
        if(current_node == src) break;
        current_node = parent[current_node];
    }
    reverse(path.begin(), path.end());
    for(int node : path) cout << node << " ";

    return 0;
}


/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1


9 15
E B 20
B C 7
B A 2
B J 6
B H 15
B F 13
J A 5
J I 6
E G 5
G F 1
F H 21
H I 7
I A 18
A C 1
C E 9

9 15
4 2 20
2 3 7
2 1 2
2 9 6
2 7 15
2 5 13
9 1 5
9 8 6
4 6 5
6 5 1
5 7 21
7 8 7
8 1 18
1 3 1
3 4 9



A = 1
B = 2
C = 3
E = 4
F = 5
G = 6
H = 7
I = 8
J = 9
*/

