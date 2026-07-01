/*
Problem: LeetCode 2812 – Find the Safest Path in a Grid

Approach:
1. Compute distance from every cell to the nearest thief:
   - Use Multi-Source BFS.
   - Push all thief cells (grid[i][j] == 1)
     into the queue initially.
   - dist[i][j] stores minimum distance to a thief.
2. Run BFS:
   - Expand simultaneously from all thieves.
   - Fill shortest distance for every cell.
3. Find path with maximum safeness factor:
   - Use a Max Heap (Priority Queue).
   - State = {current safeness, x, y}.
4. Start from (0,0):
   - Initial safeness = dist[0][0].
5. For every move:
   - Path safeness becomes:
       min(current safeness,
           dist[next cell])
6. Always process the path with the
   highest safeness first.
7. Maintain:
   - best[x][y]
     = maximum safeness achieved so far
       for cell (x,y).
8. When destination (n-1,n-1) is reached:
   - Return its safeness value.

Key Idea:
- Multi-source BFS gives danger distance
  for every cell.
- Then apply a Dijkstra-like algorithm
  that maximizes the minimum value
  along the path.

Time Complexity: O(N² log N)
Space Complexity: O(N²)
*/

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS from all thieves
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 &&
                   nx < n && ny < n &&
                   dist[nx][ny] == INT_MAX) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<vector<int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int x = cur[1];
            int y = cur[2];

            if(x == n - 1 && y == n - 1)
                return safe;

            if(safe < best[x][y])
                continue;

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 &&
                   nx < n && ny < n) {

                    int nsafe = min(safe, dist[nx][ny]);

                    if(nsafe > best[nx][ny]) {
                        best[nx][ny] = nsafe;
                        pq.push({nsafe, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};
