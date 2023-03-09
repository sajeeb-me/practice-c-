#include<bits/stdc++.h>
using namespace std;

void adjacency_matrix_to_list()
{
    int nodes = 4;

    int matrix[nodes][nodes];

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
            matrix[i][j] = 0 ;
    }

    matrix[0][1] = 1;
    matrix[1][0] = 1;

    matrix[1][2] = 1;
    matrix[2][1] = 1;

    matrix[1][3] = 1;
    matrix[3][1] = 1;

    matrix[2][3] = 1;
    matrix[3][2] = 1;

    cout << "Adjacency matrix : \n";
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    vector<vector<int>> adj_list(nodes);
    for(int i=0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            if(matrix[i][j] == 1)
                adj_list[i].push_back(j);

    cout << "\nConverted Adjacency list : \n";
    for(int i=0; i<nodes; i++)
    {
        cout << i << "-> ";
        for(int j=0; j<adj_list[i].size(); j++)
            cout << adj_list[i][j]<< ", " ;
        cout << "\n";
    }

}

void adjacency_list_to_matrix()
{
    int nodes = 4;
    vector<int> adj_list[nodes];

    adj_list[0] = { 1 };
    adj_list[1] = { 0, 2, 3 };
    adj_list[2] = { 1, 3 };
    adj_list[3] = { 1, 2 };

    cout << "\n\nAdjacency list : \n";
    for(int i=0; i<nodes; i++)
    {
        cout << i << "-> ";
        for(int j=0; j<adj_list[i].size(); j++)
            cout << adj_list[i][j]<< ", " ;
        cout << "\n";
    }

    int matrix[nodes][nodes];
    for(int i =0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            matrix[i][j] = 0;

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<adj_list[i].size(); j++)
        {
            matrix[i][adj_list[i][j]] = 1;
        }
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
    adjacency_matrix_to_list();
    adjacency_list_to_matrix();

    return 0;
}
