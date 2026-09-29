/*
Problem:
---------
LeetCode 2267 - Check if There Is a Valid Parentheses String Path

Approach:
---------
1. We need to find a path from the top-left cell to the bottom-right cell.
   At every step, we can move:
   - Down
   - Right

2. While traversing the path, maintain `cnt`:
   - `cnt` represents the current balance of parentheses.
   - If the current cell contains `(`, increase `cnt`.
   - If the current cell contains `)`, decrease `cnt`.

3. If at any point:

       cnt < 0

   then there are more closing parentheses than opening parentheses.
   Such a path can never become valid, so return false.

4. Use an important pruning condition:

       remaining = (m - 1 - i) + (n - 1 - j)

   This represents the number of moves still available to reach the
   destination.

   If:

       cnt > remaining

   then there are not enough remaining cells to close all currently
   open parentheses.

   So this path can never become valid and we return false.

5. At the destination:
   - The parenthesis balance must be exactly zero.

       cnt == 0

   If it is zero, the path forms a valid parentheses string.

6. Use 3D DP / memoization:

       dp[i][j][cnt]

   stores whether it is possible to reach the destination from position
   `(i, j)` when the current parentheses balance is `cnt`.

7. Before solving a state, check whether it has already been calculated:

       if(dp[i][j][cnt] != -1)

   If yes, return the stored result.

8. From every valid state, try both possible directions:

       down  = solve(i + 1, j, ...)
       right = solve(i, j + 1, ...)

   If either path works, the current state is valid.

9. Before starting DFS, perform two quick checks:
   - The total number of cells must be odd, because a valid parentheses
     string must have an even number of characters.
   - The first cell must be `(`, otherwise the balance becomes negative
     immediately.

Key Idea:
---------
This is a path + parentheses balance problem.

For any valid parentheses string:

    balance must never become negative
    balance must be 0 at the end

So while moving through the grid, we maintain:

    cnt = number of '(' - number of ')'

For every cell:

    '(' -> cnt++
    ')' -> cnt--

The important optimization is memoization.

The same cell `(i, j)` can be reached through many different paths with
the same balance `cnt`. Once we know the answer for:

    (i, j, cnt)

we do not need to solve that state again.

The additional pruning:

    cnt > remaining

is also important because every remaining cell can decrease the balance
by at most 1. If there aren't enough cells left, reaching balance 0 is
impossible.

Example:
--------
grid =
    ( (
    ) )

Path:

    ( -> ( -> ) -> )

Balance:

    0
    1
    2
    1
    0

The balance never becomes negative and ends at 0.

Therefore, this path is valid.

Answer = true.

Example 2:
----------
grid =
    ( )
    ) (

Starting from:

    (

If we move down:

    ( -> )

balance becomes:

    1 -> 0

But the remaining path can be checked using the same balance logic.

If at any point we encounter too many `)` and:

    cnt < 0

that path is immediately rejected.

Time Complexity:
----------------
O(m × n × (m + n))

There are at most:

    m × n

different cells and the balance `cnt` can range up to O(m + n).

Each state is calculated only once, and each state checks at most two
transitions.

Space Complexity:
-----------------
O(m × n × (m + n))

The 3D DP array stores one state for every:

    (row, column, balance)

The recursive call stack also uses O(m + n) space, which is dominated
by the DP space.
*/


// class Solution {
// public:
//     bool solve(int i, int j, vector<vector<char>>& grid, int m, int n, int cnt) {
//         if(i >= m || j >= n) return false;
//         if(grid[i][j] == '(') cnt++;
//         else cnt--;

//         if(cnt < 0) return false;

//         if(i == m - 1 && j == n - 1) return cnt == 0;

//         return solve(i + 1, j, grid, m, n, cnt) || solve(i, j + 1, grid, m, n, cnt);
//     }

//     bool hasValidPath(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         if((m + n - 1) % 2 != 0) return false;
//         if(grid[0][0] == ')') return false;
//         return solve(0, 0, grid, m, n, 0);
//     }
// };



// class Solution {
// public:
//     vector<vector<vector<int>>> dp;
//     bool solve(int i, int j, vector<vector<char>>& grid, int m, int n, int cnt) {
//         if(i >= m || j >= n) return false;
//         if(grid[i][j] == '(') cnt++;
//         else cnt--;
//         
//         if(cnt < 0) return false;

//         // Remaining cells including current destination
//         int remaining = (m - 1 - i) + (n - 1 - j);
//         // We need enough ')' to close all '('
//         if(cnt > remaining) return false;

//         if(i == m - 1 && j == n - 1) return cnt == 0;

//         if(dp[i][j][cnt] != -1) return dp[i][j][cnt];

//         bool down = solve(i + 1, j, grid, m, n, cnt);
//         bool right = solve(i, j + 1, grid, m, n, cnt);

//         return dp[i][j][cnt] = down || right;
//     }

//     bool hasValidPath(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         if((m + n - 1) % 2 != 0) return false;
//         if(grid[0][0] == ')') return false;
//         dp.resize(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
//         return solve(0, 0, grid, m, n, 0);
//     }
// };


class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool solve(int i, int j, vector<vector<char>>& grid, int m, int n, int cnt) {
        if(i >= m || j >= n) return false;
        if(grid[i][j] == '(') cnt++;
        else cnt--;
        
        if(cnt < 0) return false;

        // Remaining cells including current destination
        int remaining = (m - 1 - i) + (n - 1 - j);
        // We need enough ')' to close all '('
        if(cnt > remaining) return false;

        if(i == m - 1 && j == n - 1) return cnt == 0;

        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];

        bool down = solve(i + 1, j, grid, m, n, cnt);
        bool right = solve(i, j + 1, grid, m, n, cnt);

        return dp[i][j][cnt] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if((m + n - 1) % 2 != 0) return false;
        if(grid[0][0] == ')') return false;
        dp.resize(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        return solve(0, 0, grid, m, n, 0);
    }
};
