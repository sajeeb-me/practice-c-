#include<bits/stdc++.h>
using namespace std;

/*
0 --- 1
     / \
   2 --- 3

0 -> 1
1 -> 0
1 -> 2
2 -> 1
1 -> 3
3 -> 1
2 -> 3
3 -> 2


adj matrix:
Space complexity = O(n^2)
Time complexity = O(n^2)

*/

int main()
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

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
