#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[5];

    for(int i=0; i<5; i++)
        cin >> a[i];

    int sum = 0;
    for(int i=0; i<5; i++)
        sum += a[i];

    int result = 1;
    for(int i=0; i<5; i++)
        result *= a[i];

    cout << sum << "\n";
    cout << result << "\n";

    return 0;
}
