/*
Problem: Count Submatrices with Equal Number of X and Y

Approach:
1. Build two 2D prefix sum matrices for counts of 'X' and 'Y'.
2. For each cell, compute cumulative counts using inclusion-exclusion.
3. Compare prefixX and prefixY at each cell.
4. If both counts are equal and greater than 0, increment the count.
5. Each valid prefix represents a submatrix from (0,0) to (i,j).

Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> prefixX(n, vector<int>(m,0));
        vector<vector<int>> prefixY(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X'){
                    prefixX[i][j] = 1;
                }
                if(grid[i][j] == 'Y'){
                    prefixY[i][j] = 1;
                }

                if(i > 0){
                    prefixX[i][j] += prefixX[i - 1][j];
                    prefixY[i][j] += prefixY[i - 1][j];
                }

                if(j > 0){
                    prefixX[i][j] += prefixX[i][j - 1];
                    prefixY[i][j] += prefixY[i][j - 1];
                }

                if(i > 0 && j > 0){
                    prefixX[i][j] -= prefixX[i - 1][j - 1];
                    prefixY[i][j] -= prefixY[i - 1][j - 1];
                }

                if(prefixX[i][j] == prefixY[i][j] && prefixX[i][j] > 0) count++;
            }
        }
        return count;
    }
};
