/*
Problem: LeetCode 1510 – Stone Game IV

Approach:
1. This is a Game Theory + Dynamic Programming problem.
2. `solve(n)` tells us whether the current player can
   win when there are `n` stones remaining.
3. Base Case:
   - If n == 0:
       → No move is possible.
       → Current player loses.
       → return false
4. Check all possible square numbers:
      1², 2², 3², ... <= n
5. Try removing every possible square.
6. After removing i²:
      solve(n - i²)
   tells us whether the opponent can win.
7. If we find even ONE move where:
      solve(n - i²) == false
   then the opponent loses after our move.
   Therefore, current player wins.
8. If every possible move allows the opponent
   to win, the current player loses.
9. Use `dp` to store already calculated states.

Key Idea:
- A position is winning if there exists at least
  one move that takes the opponent to a losing state.

Example:
n = 2

Possible move:
Remove 1² = 1

Remaining:
2 - 1 = 1

For n = 1:
Remove 1² → remaining 0
solve(0) = false

Therefore:
solve(1) = true

For n = 2:
The opponent gets n = 1, which is winning.
So n = 2 is losing.

Time Complexity: O(N√N)
Space Complexity: O(N)
*/

class Solution {
public:

    bool solve(int n, vector<int>& dp) {

        // No stones left means current player loses
        if(n == 0)
            return false;

        // Return already calculated result
        if(dp[n] != -1)
            return dp[n];

        // Try removing every possible square number
        for(int i = 1; i * i <= n; i++) {

            // If opponent loses after this move,
            // current player wins
            if(solve(n - i * i, dp) == false)
                return dp[n] = true;
        }

        // No winning move was found
        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {

        // dp[n] stores whether n is a winning state
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};
