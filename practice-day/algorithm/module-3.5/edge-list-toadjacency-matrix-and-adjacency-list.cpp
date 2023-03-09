#include<bits/stdc++.h>
using namespace std;


void edgeToList(vector<vector<int>>&edge)
{
    int nodes = edge.size();
    vector<vector<int>>adj_list(nodes);
    for(int i=0; i<nodes; i++)
    {
        adj_list[edge[i][0]].push_back(edge[i][1]);
        adj_list[edge[i][1]].push_back(edge[i][0]);
    }

    cout << "\nConverted Adjacency list : \n";
    for(int i=0; i<nodes; i++)
    {
        cout << i << "-> ";
        for(int j=0; j<adj_list[i].size(); j++)
            cout << adj_list[i][j]<< ", " ;
        cout << "\n";
    }
}

void edgeToMatrix(vector<vector<int>>&edge)
{
    int nodes = edge.size();

    int matrix[nodes][nodes];
    for(int i =0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            matrix[i][j] = 0;

    for(int i=0; i<nodes; i++)
    {
        matrix[edge[i][0]][edge[i][1]] = 1;
        matrix[edge[i][1]][edge[i][0]] = 1;
    }

    cout << "\nConverted Adjacency matrix : \n";
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    int nodes = 4;
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;

    vector< vector<int> > edge_list;
    for(int i = 0 ; i < m ; i++)   // loop over the number of edges
    {
        int u, v;
        cin >> u >> v; // there exists an edge between node u and v

        edge_list.push_back({u, v});
    }

   cout << "Edge list : \n";
    for(int i=0; i<edge_list.size(); i++)
        cout << edge_list[i][0] << ", " << edge_list[i][1] << "\n";

    edgeToList(edge_list);
    edgeToMatrix(edge_list);

    return 0;
}
