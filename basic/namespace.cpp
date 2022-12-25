#include<bits/stdc++.h>

using namespace std;

int x = 5;

namespace My
{
int x = 10;
}

int main()
{
    cout << My::x;

    return 0;
}
