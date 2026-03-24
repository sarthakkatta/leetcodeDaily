/*
Problem: LeetCode 2906 – Construct Product Matrix

Approach:
1. Treat the matrix as a flattened array.
2. First pass (prefix): store product of all previous elements.
3. Second pass (suffix): multiply with product of all next elements.
4. Use modulo 12345 at every step to avoid overflow.
5. This avoids division and handles zero values correctly.

Time Complexity: O(N * M)
Space Complexity: O(1) (excluding output)
*/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> p(n, vector<int>(m, 1));

        long long prefix = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                p[i][j] = prefix;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        long long suffix = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                p[i][j] = (p[i][j] * suffix) % MOD;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }
        return p;
    }
};
