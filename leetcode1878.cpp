/*
Problem: LeetCode 1878 – Get Biggest Three Rhombus Sums in a Grid

Approach:
1. Precompute prefix sums for both diagonals (top-left→bottom-right and top-right→bottom-left).
2. For each cell treat it as the center of a rhombus.
3. For every possible side length, compute the rhombus border sum using diagonal prefix sums.
4. Handle the special case when side length = 0 (single cell).
5. Maintain a set to keep only the top three unique sums.

Time Complexity: O(M * N * min(M,N))
Space Complexity: O(M * N)
*/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> d1(m, vector<int>(n));
        vector<vector<int>> d2(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                d1[i][j] = grid[i][j];
                if(i > 0 && j > 0)
                    d1[i][j] += d1[i-1][j-1];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = n-1; j >= 0; j--){
                d2[i][j] = grid[i][j];
                if(i > 0 && j+1 < n)
                    d2[i][j] += d2[i-1][j+1];
            }
        }
        set<int> st;
        auto addToSet = [&](int val){
            st.insert(val);
            if(st.size() > 3)
                st.erase(st.begin());
        };
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                addToSet(grid[r][c]);
                for(int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++) {
                    int sum = 0;
                    int top_r = r-side, top_c = c;
                    int right_r = r, right_c = c+side;
                    int bottom_r = r+side, bottom_c = c;
                    int left_r = r, left_c = c-side;
                    sum += d1[right_r][right_c];
                    if(top_r-1 >= 0 && top_c-1 >= 0)
                        sum -= d1[top_r-1][top_c-1];
                    sum += d2[bottom_r][bottom_c];
                    if(right_r-1 >= 0 && right_c+1 < n)
                        sum -= d2[right_r-1][right_c+1];
                    sum += d1[bottom_r][bottom_c];
                    if(left_r-1 >= 0 && left_c-1 >= 0)
                        sum -= d1[left_r-1][left_c-1];
                    sum += d2[left_r][left_c];
                    if(top_r-1 >= 0 && top_c+1 < n)
                        sum -= d2[top_r-1][top_c+1];
                    sum -= grid[top_r][top_c];
                    sum -= grid[right_r][right_c];
                    sum -= grid[bottom_r][bottom_c];
                    sum -= grid[left_r][left_c];
                    addToSet(sum);
                }
            }
        }
        return vector<int>(st.rbegin(), st.rend());
    }
};
