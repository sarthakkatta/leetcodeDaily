/*
Problem: LeetCode 799 – Champagne Tower


Approach:
1. Use a 2D array to simulate pouring champagne.
2. Start by pouring into top glass.
3. If any glass overflows (>1), split extra equally to next row.
4. Continue until query_row.
5. Return value at query position.

Time Complexity: O(N * N)
Space Complexity: O(N * N)
*/


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        double tower[102][102] = {0.0};

        tower[0][0] = (double)poured;

        for(int r = 0; r <= query_row; r++){

            for(int c = 0; c <= r; c++){

                if(tower[r][c] > 1.0){

                    double extra = (tower[r][c] - 1.0) / 2.0;

                    tower[r][c] = 1.0;

                    tower[r + 1][c] += extra;

                    tower[r + 1][c + 1] += extra;
                }
            }
        }

        return tower[query_row][query_glass];
    }
};
