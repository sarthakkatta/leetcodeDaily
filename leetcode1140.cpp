/*
Problem: LeetCode 1140 – Stone Game II

Approach:
1. This is a Game Theory + Dynamic Programming problem.
2. `person` tells whose turn it is:
   - 1 → Alice
   - 0 → Bob
3. `i` represents the current index in piles.
4. `M` controls how many piles the current player
   is allowed to take:
      1 <= X <= 2 * M
5. After taking X piles:
      M = max(M, X)
   for the next player.
6. Alice wants to maximize the number of stones
   she gets.
7. Bob wants to minimize Alice's final score.
8. Therefore:
   - Alice uses `max()`
   - Bob uses `min()`
9. `dp[person][i][M]` stores the result for a
   particular game state.
10. For every possible X:
    - Add the stones taken from the current piles.
    - Recursively solve the remaining game.
11. If it is Alice's turn:
       result = max(result,
                    stones + nextResult)
12. If it is Bob's turn:
       result = min(result, nextResult)
    because Bob does not add stones to Alice's score.
13. Base Case:
    - If all piles are consumed, return 0.

Key Idea:
- Alice maximizes her total stones.
- Bob minimizes Alice's total stones.
- Memoization avoids recalculating the same
  `(person, i, M)` state.

Example:
piles = [2, 7, 9, 4, 4]

Alice starts with:
i = 0, M = 1

She can take:
X = 1 or X = 2

After taking X piles:
M becomes max(M, X)

Both players continue optimally.

Time Complexity: O(N^3)
Space Complexity: O(N^3)
*/

class Solution {
public:
    int n;

    int solveForAlice(
        vector<int>& piles,
        int person,
        int i,
        int M,
        vector<vector<vector<int>>>& dp
    ) {

        // No piles left
        if(i >= n)
            return 0;

        // Return already calculated state
        if(dp[person][i][M] != -1)
            return dp[person][i][M];

        // Alice wants to maximize.
        // Bob wants to minimize Alice's score.
        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        // Current player can take X piles
        // where 1 <= X <= 2 * M
        for(int x = 1; x <= min(2 * M, n - i); x++) {

            // Add the current pile
            stones += piles[i + x - 1];

            if(person == 1) { // Alice

                // Alice adds the stones she takes
                // and tries to maximize her score
                result = max(
                    result,
                    stones + solveForAlice(
                        piles,
                        0,
                        i + x,
                        max(M, x),
                        dp
                    )
                );
            }
            else { // Bob

                // Bob does not add to Alice's score.
                // He tries to minimize Alice's final score.
                result = min(
                    result,
                    solveForAlice(
                        piles,
                        1,
                        i + x,
                        max(M, x),
                        dp
                    )
                );
            }
        }

        return dp[person][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // dp[2][n+1][n+1]
        // person × index × M
        vector<vector<vector<int>>> dp(
            2,
            vector<vector<int>>(
                n + 1,
                vector<int>(n + 1, -1)
            )
        );

        // Alice starts:
        // person = 1
        // i = 0
        // M = 1
        return solveForAlice(piles, 1, 0, 1, dp);
    }
};
