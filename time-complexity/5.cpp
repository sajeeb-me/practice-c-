#include<bits/stdc++.h>

using namespace std;

/*

Time complexity = O(2^n)
Memory complexity = O(n)

if ans saved:
    Time complexity = O(n)
    Memory complexity = O(n)

*/

int countt = 0;
int save[100];

int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(save[n] != 0)
        return save[n];
    int x = fib(n-1);
    countt++;
    int y = fib(n-2);
    countt++;
    save[n] = x+y;
    return x+y;
}

int main()
{
    int n; // O(1)
    cin >> n;

    int ans = fib(n);
    cout << "ans = " << ans << "\n";
    cout << "count = " << countt << "\n";

    return 0;
}

