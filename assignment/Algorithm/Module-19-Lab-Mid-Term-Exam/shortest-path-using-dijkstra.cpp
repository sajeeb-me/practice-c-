#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 1e9;

vector<pair<int, int>>adj_list[N];

int d[N], visited[N], parent[N];

void dijkstra(int src)
{
    d[src] = 0;

    priority_queue<pair<int, int>>pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        pair<int, int> head = pq.top();
        pq.pop();

        int selected_node = head.second;
        if(visited[selected_node]) continue;
        visited[selected_node] = 1;

        for(auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int adj_cst = adj_entry.second;

            if(d[selected_node]+ adj_cst < d[adj_node])
            {
                d[adj_node] = d[selected_node]+adj_cst;
                parent[adj_node] = selected_node;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) d[i]=INF;

    for(int i=0; i<m; i++)
    {
        int ai, bi, wi;
        cin >> ai >> bi >> wi;
        adj_list[ai].push_back({bi, wi});
        adj_list[bi].push_back({ai, wi});
    }

    int src = 1;
    dijkstra(src);

    if(!visited[n]) cout << "-1\n";
    else
    {
        int current_node = n;
        vector<int> path;

        while(1)
        {
            path.push_back(current_node);
            if(current_node == src) break;
            current_node = parent[current_node];
        }
        reverse(path.begin(), path.end());
        for(int node : path) cout << node << " ";
    }

    return 0;
}
/*
10 10
1 4 201
2 3 238
3 4 40
3 6 231
3 8 45
4 5 227
4 6 58
4 9 55
5 7 14
6 10 242

*/
