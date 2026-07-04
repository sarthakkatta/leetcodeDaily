/*
Problem: LeetCode 2492 – Minimum Score of a Path Between Two Cities

Approach:
1. Build an undirected weighted graph:
   - Each road connects two cities with a score.
2. Create an adjacency list:
   - adj[u] = {v, weight}
3. Start BFS from city 1.
4. Maintain:
   - visited array
   - answer = minimum road weight seen so far
5. During traversal:
   - For every adjacent road:
       answer = min(answer, road weight)
6. Visit all cities reachable from city 1.
7. Since city n belongs to the same connected
   component as city 1, the minimum edge
   encountered in this component can always
   be part of a valid path.
8. Return the minimum score found.

Key Idea:
- The score of a path is the minimum edge
  weight on that path.
- Any edge in the connected component of
  city 1 can potentially be used by revisiting
  cities, so the answer is simply the smallest
  edge weight in that component.

Time Complexity: O(N + M)
Space Complexity: O(N + M)

where:
- N = number of cities
- M = number of roads
*/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);

        queue<int> q;
        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &[nei, wt] : adj[node]) {

                ans = min(ans, wt);

                if(!vis[nei]) {
                    vis[nei] = true;
                    q.push(nei);
                }
            }
        }

        return ans;
    }
};
