/*
Problem: LeetCode 1727 – Largest Submatrix With Rearrangements

Approach:
1. Treat each row as a histogram by computing heights of consecutive 1s column-wise.
2. For each row, build the height array using values from the previous row.
3. Sort each row in descending order to maximize width with taller heights.
4. For each position, calculate area = height * width.
5. Keep track of the maximum area across all rows.

Time Complexity: O(N * M log M)
Space Complexity: O(N * M)
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            heights[0][i] = matrix[0][i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    if(i == 0) heights[i][j] = 1;
                    else heights[i][j] = heights[i-1][j] + 1;
                }else{
                    heights[i][j] = 0;
                }
            }
        }
        int maxarea = 0;
        for(int i = 0; i < heights.size(); i++){
            vector<int> curr(heights[i].begin(), heights[i].end());
            sort(curr.rbegin(), curr.rend());
            for(int i = 0; i < curr.size(); i++){
                maxarea = max(maxarea,(curr[i] * (i + 1)));
            }
        }
        return maxarea;
    }
};
