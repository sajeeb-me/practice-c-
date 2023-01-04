#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int>arr;
    arr.resize(27);

    for(int i=1; i<=26; i++)
        arr[i]=0;

    for(int i=0; i<3; i++)
        arr[s[i]-'a'+1]++;

    int count = 1;
    for(int i=1; i<=26; i++)
    {
        if(arr[i]>count)
            count = arr[i];
    }

    switch(count)
    {
    case 1:
        cout << 6;
        break;
    case 2:
        cout << 3;
        break;
    default:
        cout << 1;
        break;
    }

    return 0;
}
