/*
Problem: LeetCode 1594 – Maximum Non Negative Product in a Matrix

Approach:
1. Use Dynamic Programming with two matrices: dpMax and dpMin.
2. dpMax[i][j] stores the maximum product to reach cell (i,j).
3. dpMin[i][j] stores the minimum product (to handle negatives).
4. For each cell, consider top and left transitions.
5. Multiply current value with both max and min from previous cells.
6. Take max for dpMax and min for dpMin.
7. Final answer is dpMax[n-1][m-1], return -1 if negative.

Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // dpMax[i][j] = max product till (i,j)
        // dpMin[i][j] = min product till (i,j)
        vector<vector<long long>> dpMax(n, vector<long long>(m, 0));
        vector<vector<long long>> dpMin(n, vector<long long>(m, 0));

        dpMax[0][0] = dpMin[0][0] = grid[0][0];

        // First row
        for (int j = 1; j < m; j++) {
            dpMax[0][j] = dpMin[0][j] = dpMax[0][j-1] * grid[0][j];
        }

        // First column
        for (int i = 1; i < n; i++) {
            dpMax[i][0] = dpMin[i][0] = dpMax[i-1][0] * grid[i][0];
        }

        // Fill rest
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                long long val = grid[i][j];

                long long a = dpMax[i-1][j] * val;
                long long b = dpMin[i-1][j] * val;
                long long c = dpMax[i][j-1] * val;
                long long d = dpMin[i][j-1] * val;

                dpMax[i][j] = max({a, b, c, d});
                dpMin[i][j] = min({a, b, c, d});
            }
        }

        long long ans = dpMax[n-1][m-1];

        if (ans < 0) return -1;

        return ans % 1000000007;
    }
};
