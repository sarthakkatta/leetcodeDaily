/*
Problem: LeetCode 3310 – Remove Methods From Project

Approach:
1. Build a directed graph:
   - Each invocation u -> v means
     method u calls method v.
2. Perform BFS starting from method k:
   - Mark all methods reachable from k
     as suspicious (visited).
3. After traversal:
   - Check every invocation.
   - If there exists an edge:
         non-suspicious -> suspicious
     then suspicious methods cannot be
     removed independently.
   - In this case, return all methods.
4. Otherwise:
   - Return only the methods that are
     not marked suspicious.

Key Idea:
- First identify every method influenced
  by method k using BFS.
- If any safe method depends on a suspicious
  method, removing only suspicious methods
  would break the project.
- Otherwise, all non-suspicious methods
  remain after removal.

Example:
n = 4
k = 1

Invocations:
1 -> 2
2 -> 3

Suspicious:
1, 2, 3

Remaining:
0

Output:
[0]

Time Complexity: O(N + E)
where:
- N = number of methods
- E = number of invocations

Space Complexity: O(N + E)
*/

class Solution {
public:
    vector<int> remainingMethods(int n,
                                 int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> g(n);
        vector<int> vis(n);

        for(auto &e : invocations) {
            g[e[0]].push_back(e[1]);
        }

        queue<int> q;
        q.push(k);
        vis[k] = 1;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : g[u]) {
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        // Check whether a non-suspicious method
        // invokes a suspicious method.
        for(auto &e : invocations) {
            if(!vis[e[0]] && vis[e[1]]) {

                vector<int> ans;

                for(int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
