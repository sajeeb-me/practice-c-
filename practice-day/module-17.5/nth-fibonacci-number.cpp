#include<bits/stdc++.h>
using namespace std;

int nthFibonacci(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int main()
{
    int num;
    cin >> num;
    int ans = nthFibonacci(num);
    cout << ans;

    return 0;
}
