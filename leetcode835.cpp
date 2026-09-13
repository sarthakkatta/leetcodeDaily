/*
Problem:
---------
LeetCode 835 - Image Overlap

Approach:
---------
1. We need to find the maximum number of overlapping `1`s when matrix B
   is shifted relative to matrix A.

2. Try every possible row and column shift:
   - `rowOff` represents the vertical shift.
   - `colOff` represents the horizontal shift.
   
   Both shifts range from `-(n-1)` to `n-1`, because shifting any further
   would make the two n x n matrices completely non-overlapping.

3. For every shift, call `countOverlaps()`:
   - Traverse every cell of A.
   - Find the corresponding position in B after applying the shift:

       B_row = row + rowOff
       B_col = col + colOff

4. Check whether the corresponding B position is inside the matrix:
   - If it goes outside the boundary, ignore that position.

5. If both positions contain `1`:

       A[row][col] == 1
       B[B_row][B_col] == 1

   then this pair contributes one overlapping `1`.

6. Count the overlaps for the current shift and update:

       maxOverlap = max(maxOverlap, count)

7. After checking every possible shift, return the maximum overlap.

Key Idea:
---------
Instead of physically shifting the matrix, we simulate the shift using
row and column offsets.

For a particular shift:

    B_row = row + rowOff
    B_col = col + colOff

This tells us which position in B corresponds to the current position
in A.

We then simply count positions where both matrices contain `1`.

By trying every possible `(rowOff, colOff)` pair, we are guaranteed to
find the shift that produces the maximum overlap.

Example:
--------
A =
    1 0 0
    0 1 0
    0 0 0

B =
    0 1 0
    0 0 0
    0 0 0

If B is shifted one column to the left, its `1` can overlap with the
`1` in A.

For that particular shift:

    rowOff = 0
    colOff = -1

The function checks corresponding positions and counts the overlapping
`1`s.

The maximum over all possible shifts is returned as the answer.

Time Complexity:
----------------
There are O(n²) possible shifts.

For every shift, `countOverlaps()` checks O(n²) cells.

Therefore:

    O(n²) × O(n²) = O(n⁴)

Total Time Complexity = O(n⁴)

Space Complexity:
-----------------
O(1)

No extra matrix is created. Only a few variables are used.

*/

class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff) {
        int n = A.size();
        int count = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                int B_row = row + rowOff;
                int B_col = col + colOff;
                if(B_row < 0 || B_row >= n || B_col < 0 || B_col >= n)
                    continue;
               
                if(A[row][col] == 1 && B[B_row][B_col] == 1){
                    count++;
                }
            }
        }        
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOverlap = 0;
        for(int rowOff = -n+1; rowOff<n; rowOff++) {
            for(int collOff = -n+1; collOff<n; collOff++) {
                int count = countOverlaps(A, B, rowOff, collOff);
                maxOverlap = max(maxOverlap, count);
            }
        } 
        return maxOverlap;
    }
};
