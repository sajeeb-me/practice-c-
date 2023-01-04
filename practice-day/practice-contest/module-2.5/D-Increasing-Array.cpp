#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>a;
    a.resize(n);

    for(int i=0; i<n; i++)
        cin >> a[i];

    int count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[i])
            {
                count++;
                int temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    cout << count << "\n";
    return 0;
}
