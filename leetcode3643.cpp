/*
Problem: Flip Square Submatrix Vertically

Approach:
1. Identify the boundaries of the k x k submatrix using (x, y).
2. Use two pointers: start row and end row.
3. For each column in the submatrix, swap elements of start row with end row.
4. Move the pointers inward until all rows are reversed.
5. Return the updated grid.

Time Complexity: O(k * k)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int startR  = x;
        int endR  = x + k  - 1;
        int startC  = y;
        int endC  = y + k - 1;

        for(int i = startR ; i <= endR; i++){
            for(int j = startC; j <= endC; j++){
                swap(grid[i][j], grid[endR][j]);
            }
            endR--;
        }
        return grid;
    }
};
