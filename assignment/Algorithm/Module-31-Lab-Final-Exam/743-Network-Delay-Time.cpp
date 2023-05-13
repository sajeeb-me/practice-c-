#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src)
    {
        const int N = 1e5 + 5;
        const int INF = 1e9;

        vector<pair<int, int>>adj_list[N];

        for(int i=0; i<times.size(); i++)
            adj_list[times[i][0]].push_back({times[i][1],times[i][2]});

        vector<int>d(n+1,INF);
        d[src] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push({0,src});

        while(!pq.empty())
        {
            pair<int, int> head = pq.top();
            pq.pop();
            int selected_node = head.second;

            for(auto adj_entry : adj_list[selected_node])
            {
                int adj_node = adj_entry.first;
                int edge_cost = adj_entry.second;

                if(d[selected_node] + edge_cost < d[adj_node])
                {
                    d[adj_node] = d[selected_node] + edge_cost;
                    pq.push({d[adj_node], adj_node});
                }
            }
        }
        for(int i=1; i<n+1; i++)
            if(d[i]==1e9)
                return -1;

        return *max_element(d.begin()+1,d.end());
    }
};

int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;

    Solution s;
    cout << s.networkDelayTime(times, n, k);

    return 0;
}


/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/
