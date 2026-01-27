/*
 Problem: Minimum Cost with Modified Edge

 Approach:
 - Build adjacency list
 - Use Dijkstra (min heap)
 - Forward edge → weight w
 - Reverse edge → weight 2*w
 - Find shortest path from node 0 to node n-1

 Time Complexity: O(E log V)
 Space Complexity: O(V + E)
*/

class Solution {
public:
    vector<vector<pair<int,int>>> G;
    int dijkstra(int n){
        vector<bool> vis(n, false);
        vector<long long> dist(n, 1e18);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > Q;

        Q.push({0, 0});
        dist[0] = 0;
        while(!Q.empty()){
            int u = Q.top().second;
            Q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto [v, w] : G[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    Q.push({dist[v], v});
                }
            }
        }
        if(dist[n - 1] == 1e18) return -1;
        return dist[n - 1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        G.resize(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            G[u].push_back({v, w});
            G[v].push_back({u, 2 * w});
        }
        return dijkstra(n);
    }
};
