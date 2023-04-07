
/*

Set the value for N and INF to further use.

create a distance array, variable type should be long long so that we can take huge number input.
ex: long long dis[N]
create a visited array and mark all node to unvisited.

void dijkstra(int src)
{
    set all values of distance array to infinity.
    set source node value to 0; // dis[src] = 0.

    for i=0 to nodes-1
        - select unvisited node with minimum dis[node]
        - set visited[selected_node] = 1;
        - for all adj_node of selected_node:
            - if dis[seleted_node] + edge_cost(selected_node, adj_node) < dis[adj_node]
                - dis[adj_node] = dis[seleted_node] + edge_cost(selected_node, adj_node)
}

output array dis[];

*/
