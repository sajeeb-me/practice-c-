#include<bits/stdc++.h>
using namespace std;

int get_sum(int n)
{
    if(n == 0) return 0;
    return (n%10)+get_sum(n/10);
}

int main()
{
    int n;
    cin >> n;

    cout << get_sum(n) << "\n";

    return 0;
}
