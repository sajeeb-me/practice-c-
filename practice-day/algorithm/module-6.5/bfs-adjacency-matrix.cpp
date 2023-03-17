#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int visited[N];
int matrix[N][N];
int checked[N];

void bfs(int start)
{
    queue<int>q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << " ";

        for(int i=0; i<N; i++)
        {
            if(matrix[head][i] && !visited[i])
            {
                checked[i]++;
                q.push(i);
                visited[i] = 1;
            }
        }
    }

}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
        for(int j=0; j<edges; j++)
            matrix[i][j] = 0;

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

//    for(int i=0; i<nodes; i++)
//    {
//        for(int j=0; j<nodes; j++)
//            cout << matrix[i][j] << " ";
//        cout << "\n";
//    }

    bfs(0);
    cout << "\n";

    for (int i = 0; i < N; i++) {
        cout << i << ": " << checked[i] << "\n";
    }

    return 0;
}


/*

6 6

0 1
1 2
2 3
1 5
2 4
5 4

*/
