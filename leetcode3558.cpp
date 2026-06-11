/*
Problem: Number of Ways to Assign Edge Weights I

Approach:
1. Build adjacency list from given edges.
2. Perform BFS starting from node 1.
3. Maintain:
   - node  → current node
   - depth → distance from root
4. Track maximum depth reached during BFS.
5. After traversal:
   - Let maxd be the maximum depth.
6. Compute answer:
   - 2^(maxd - 1) mod (1e9 + 7)
7. Use Binary Exponentiation for efficient power calculation.

Key Idea:
- BFS finds the deepest level of the tree.
- Final answer depends only on maximum depth.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long a, long long b){
        long long res = 1;

        while(b){
            if(b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n + 1, 0);

        q.push({1,0});
        vis[1] = 1;

        int maxd = 0;

        while(!q.empty()){
            auto [node, depth] = q.front();
            q.pop();

            maxd = max(maxd, depth);

            for(auto ne : adj[node]){
                if(!vis[ne]){
                    vis[ne] = 1;
                    q.push({ne, depth + 1});
                }
            }
        }

        return power(2, maxd - 1);
    }
};
