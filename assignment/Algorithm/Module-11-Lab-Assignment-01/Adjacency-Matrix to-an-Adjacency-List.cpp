#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int matrix[N][N];

void convertToAdjList(int n)
{
    vector<int>adj_list[n];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(matrix[i][j] != 0) adj_list[i].push_back(j);

    for(int i=0; i<n; i++)
    {
        cout << i << ": ";
        for(int j=0; j<adj_list[i].size(); j++)
            cout << adj_list[i][j] << " ";
        cout << "\n";
    }
}


int main()
{
    int nodes;
    cin >> nodes;

    for(int i=0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            cin >> matrix[i][j];

    convertToAdjList(nodes);

    return 0;
}
