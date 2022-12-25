//#include<iostream>
//#include<fstream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);
    cout << s << "\n";

    ofstream of;
    of.open("output.txt");

    ofstream of2;
    of2.open("output2.txt");

    ifstream ifs;
    ifs.open("input.txt");

    int x;
    double y, z;
    ifs >> x >> y >> z;

    cout << x << " " << y << " " << z << "\n";

    of<<"HELLO WORLD\n";
    of2<<"HELLO WORLD output 2\n";

    of.close();
    of2.close();
    ifs.close();

    return 0;
}
