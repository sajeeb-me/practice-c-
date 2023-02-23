#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["goru"] = 2;
    mp["chagol"] = 5;
    mp["vera"] = 1;

    cout << mp["goru"] << "\n";
    cout << mp["vera"] << "\n";

    for(auto it:mp)
        cout << "Key: " << it.first << " , Value: " << it.second << "\n";

    map<int, int> mp2;
    mp2[69] = 20;
    mp2[85] = 12;
    mp2[25] = 28;

    for(auto it:mp2)
        cout << "Key: " << it.first << " , value: " << it.second << "\n";

    return 0;
}

