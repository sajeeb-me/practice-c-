#include<bits/stdc++.h>
using namespace std;

long long arr[1001];

long long fibonacci(int n)
{
    if(n <= 2) return 1;
    if(arr[n]) return arr[n];
    arr[n] = fibonacci(n-1) + fibonacci(n-2);
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n) << "\n";

    return 0;
}
