#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<int>adj_list[N];
int color[N];
int count1, count2;

void dfs(int a, int b)
{
    color[a] = b;
    if(b == 1) count1++;
    else count2++;

    for(auto adj_node : adj_list[a])
        if(!color[adj_node])
            dfs(adj_node, b == 1 ? 2 : 1);
}

int main()
{
    int t, tst=0;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        for(int i=0; i<=n; i++)
        {
            adj_list[i].clear();
            color[i] = 0;
        }

        for(int i=0; i<n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        long long ans = 0;
        for(int i=1; i<=n; i++)
        {
            if(!color[i])
            {
                count1 = 0;
                count2 = 0;
                dfs(i, 1);
                ans += max(count1, count2);
            }
        }

        cout << "Case " << ++tst << ": " << ans << "\n";
    }

    return 0;
}
