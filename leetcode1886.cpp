/*
Problem: LeetCode 1886 – Determine Whether Matrix Can Be Obtained By Rotation

Approach:
1. Rotate the matrix up to 4 times (0°, 90°, 180°, 270°).
2. After each rotation, check if the matrix equals the target.
3. Rotation is done by transposing the matrix and then reversing each row.
4. If at any rotation the matrices match, return true.
5. If none match after 4 rotations, return false.

Time Complexity: O(N^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int n;
    void rotate(vector<vector<int>>& mat) {
        //Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        //Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        for(int c = 1; c <= 4; c++) {
            bool equal = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if(!equal)
                    break;
            }

            if(equal)
                return true;
                
            rotate(mat);
        }
        return false;
    }
};
