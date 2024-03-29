<<<<<<< HEAD
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
//        for(int j=1; j<=nodes; j++)
//        {
//            if(visited[j] == 1) continue;
//            if(selected_node == -1 || d[selected_node] > d[j]) selected_node = j;
//        }

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

    int src = 1;
    dijkstra(src);

    if(visited[nodes] == 0)
    {
        cout << -1 << "\n";
        return 0;
    }

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
*/
=======
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
vector<pair<int, int>>adj_list[N];
int d[N], visited[N];
int nodes, edges;

void dijkstra(int src)
{
    for(int i=1; i<= nodes; i++) d[i] = INF;
    d[src] = 0;

    for(int i=0; i<nodes; i++)
    {
        int selected_node = -1;
        for(int j=0; j<nodes; j++)
        {
            if(visited[j] == 1) continue;
            if(selected_node == -1 || d[selected_node] > d[j]) selected_node = j;
        }
        visited[selected_node] = 1;

        for(auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if(d[selected_node] + edge_cost < d[adj_node]) d[adj_node] = d[selected_node] + edge_cost;
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

    int src = 1;
    dijkstra(src);

    for(int i=1; i<=nodes; i++) cout << d[i] << " ";
    cout << "\n";

    return 0;
}
>>>>>>> d03bbc38f0aede1c732867b4fee449ed02b8a59f
