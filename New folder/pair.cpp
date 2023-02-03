#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<pair<pair<string,string>,int>>v;
    for(int i=1; i<=n; i++)
    {
        string fName, lName;
        int age;
        cin >> fName >> lName >> age;

        v.push_back({ {fName, lName}, age });
    }
    cout << "first name |" << " last name |" << " age\n";
    for(int i=0; i<n; i++)
        cout << v[i].first.first << " | " << v[i].first.second << " | " << v[i].second << "\n";

    return 0;
}
