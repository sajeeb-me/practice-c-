#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*
    code 1:
        Time complexity = O(n) + O(n) = O(n)
        Space complexity = O(1) + O(1) + O(n) + O(n) = O(n)
    */
    int a = 0, b = 0;
    int matrix[N][M];
    for (i = 0; i < N; i++)
    {
        a = a + i;
        matrix[i][i] = a;
    }
    for (j = 0; j < M; j++)
    {
        b = b + 2 * j;
    }


    /*
    code 2:
        Time complexity = O(n) * O(n) = O(n^2)
        Space complexity = O(1) + O(n) = O(n)
    */
    int a = 0;
    for (i = 0; i < N; i++)
    {
        for (j = N; j > i; j--)
        {
            a = a + i + j;
        }
    }


    /*
    code 3:
        Time complexity = O(log n)
        Space complexity = O(log n)
    */
    int a = 0, i = N;
    vector<int> vec;
    while (i > 0)
    {
        a += i;
        i /= 2;
        vec.push_back(a);
    }


    return 0;
}
