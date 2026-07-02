/*
Problem: LeetCode 3286 – Find a Safe Walk Through a Grid

Approach:
1. Treat the grid as a graph:
   - Cell value 0 → cost 0
   - Cell value 1 → cost 1
2. Use 0-1 BFS to find the minimum health loss.
3. Maintain:
   - dist[i][j] = minimum damage taken
     to reach cell (i, j).
4. Initialize:
   - dist[0][0] = grid[0][0]
   - Push starting cell into deque.
5. For every neighboring cell:
   - New cost =
       dist[x][y] + grid[nx][ny]
6. If a better path is found:
   - Update distance.
   - If cost added is 0:
       push_front()
   - If cost added is 1:
       push_back()
7. Once destination is reached:
   - Check whether total damage
     is strictly less than health.
8. Return:
   - true  → safe walk exists
   - false → otherwise

Key Idea:
- Edge weights are only 0 or 1,
  making 0-1 BFS more efficient than Dijkstra.
- We only need to know if minimum damage
  is less than available health.

Time Complexity: O(M × N)
Space Complexity: O(M × N)
*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            if (x == m - 1 && y == n - 1)
                return dist[x][y] < health;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int w = grid[nx][ny];

                if (dist[x][y] + w < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + w;

                    if (w == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};
