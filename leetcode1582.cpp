/*
Problem: LeetCode 1582 – Special Positions in a Binary Matrix


Approach:
1. Count number of 1s in each row and each column.
2. Store counts in rowC and colC arrays.
3. Traverse matrix again.
4. If cell is 1 and row count == 1 and column count == 1,
   then it is a special position.
5. Count such positions and return result.

Time Complexity: O(N * M)
Space Complexity: O(N + M)
*/


class Solution{
public:
    int numSpecial(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();

        vector<int> rowC(n, 0);
        vector<int> colC(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    rowC[i]++;
                    colC[j]++;
                }
            }
        }

        int special = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1 && rowC[i] == 1 && colC[j] == 1){
                    special++;
                }
            }
        }

        return special;
    }
};
