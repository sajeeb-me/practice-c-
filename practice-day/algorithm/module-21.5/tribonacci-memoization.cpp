#include<bits/stdc++.h>
using namespace std;

/*
time complexity: O(n)
space complexity: O(n)
*/

const int N = 101;
long long arr[N];

long long tribonacci(int n)
{
    if(n <= 3) return 1;    // base case
    if(arr[n]) return arr[n];   // dp state
    arr[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);   // relation
    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << tribonacci(n) << "\n";

    return 0;
}
