/*
Problem:Count Submatrices with Top-Left Element and Sum Less Than k

Approach:
1. Convert the grid into a 2D prefix sum matrix.
2. First compute prefix sums for the first row and first column.
3. For remaining cells, use inclusion-exclusion to build prefix sums.
4. Each cell now represents the sum of submatrix from (0,0) to (i,j).
5. Count how many such prefix sums are <= k.

Time Complexity: O(N * M)
Space Complexity: O(1)
*/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 1; i < n; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && j > 0)
                    grid[i][j] += ((grid[i - 1][j] + grid[i][j - 1]) -
                                   grid[i - 1][j - 1]);
                if (grid[i][j] <= k)
                    ans++;
            }
        }
        return ans;
    }
};
