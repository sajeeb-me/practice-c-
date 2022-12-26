#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
//    cin >> s;
    s.erase(s.begin());
    s.pop_back();
    cout << s << "\n";
    cout << "Size : " << s.size() << "\n";

    return 0;
}
