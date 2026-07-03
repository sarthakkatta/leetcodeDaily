/*
Problem:  Network Recovery Pathways

Approach:
1. Build a directed weighted graph:
   - graph[u] = {v, weight}
2. Compute:
   - indegree of every node
   - maximum edge weight
3. Perform Topological Sort using Kahn's Algorithm:
   - Store nodes in topo order.
4. Binary Search on the answer:
   - Let minEdgeValue be the minimum allowed
     edge weight on the path.
5. For each candidate minEdgeValue:
   - Check if a valid path exists from
     node 0 to node n-1.
6. Validation Function:
   a) Use DP on the DAG.
   b) dist[node] =
      minimum path cost to reach node.
   c) Process nodes in topological order.
   d) Ignore:
      - Offline intermediate nodes
      - Edges with weight < minEdgeValue
   e) Relax valid outgoing edges.
7. If:
      dist[n-1] <= k
   then the score is achievable.
8. Binary Search:
   - Achievable → try larger score.
   - Not achievable → try smaller score.
9. Return the maximum achievable score.

Key Idea:
- Binary Search the minimum edge value.
- Use DAG shortest-path DP to verify
  whether a valid path exists within
  the allowed total cost k.

Time Complexity:
- Topological Sort: O(V + E)
- Check Function: O(V + E)
- Binary Search: O(log W)

Overall:
O((V + E) * log W)

where:
- V = number of nodes
- E = number of edges
- W = maximum edge weight

Space Complexity:
O(V + E)
*/

class Solution {
public:
    bool canAchieveScore(
        int minEdgeValue,
        int n,
        vector<vector<pair<int,int>>>& graph,
        vector<int>& topo,
        vector<bool>& online,
        long long k
    ){
        long long INF = 1e18;

        vector<long long> dist(n, INF);
        dist[0] = 0;

        for(int node : topo){
            if(dist[node] == INF)
                continue;

            // Intermediate nodes must be online
            if(node != 0 && node != n - 1 &&
               !online[node])
                continue;

            for(auto edge : graph[node]){
                int nextNode = edge.first;
                int cost = edge.second;

                // Keep only edges having
                // value >= minEdgeValue
                if(cost < minEdgeValue)
                    continue;

                // Intermediate destination
                // node must be online
                if(nextNode != n - 1 &&
                   !online[nextNode])
                    continue;

                dist[nextNode] =
                    min(dist[nextNode],
                        dist[node] + cost);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(
        vector<vector<int>>& edges,
        vector<bool>& online,
        long long k
    ){
        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);

        int maxEdge = 0;

        // Build graph
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            graph[u].push_back({v, w});
            indegree[v]++;

            maxEdge = max(maxEdge, w);
        }

        // Topological Sort
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto edge : graph[node]){
                int nextNode = edge.first;

                indegree[nextNode]--;

                if(indegree[nextNode] == 0)
                    q.push(nextNode);
            }
        }

        // Binary Search on answer
        int low = 0;
        int high = maxEdge;
        int answer = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canAchieveScore(
                mid, n, graph,
                topo, online, k)) {

                answer = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return answer;
    }
};
