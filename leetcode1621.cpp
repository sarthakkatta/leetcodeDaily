/*
Problem:
---------
LeetCode 1621 - Number of Sets of K Non-Overlapping Line Segments

Approach:
---------
1. The first two approaches use the same DP state but calculate the
   `take` transition by repeatedly summing all possible next states.

2. In the Memoization approach:
   - `dp[k][i]` represents the number of ways to create `k` line segments
     using points from index `i` onward.
   - For every possible next point `j`, we call:
       solve(n, k - 1, j, dp)
   - Although memoization avoids recalculating the same states, the loop
     over all `j` makes the transition O(n).

3. The Bottom-Up approach removes recursion and calculates the same DP
   iteratively.
   - However, for every state `dp[k][i]`, it still loops through all
     possible `j`.
   - Therefore, it still has an O(K * n²) transition cost and can give
     TLE.

4. Optimized approach:
   - The expensive part is calculating:

       dp[k-1][i+1] + dp[k-1][i+2] + ... + dp[k-1][n-1]

   - Instead of calculating this sum again for every `i`, create a
     prefix/suffix sum array called `prevRowSum`.

5. Build `prevRowSum`:
   - `prevRowSum[x]` stores:

       dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]

   - We calculate it from right to left:

       prevRowSum[x] =
           prevRowSum[x+1] + dp[k-1][x]

6. Now the entire `take` transition can be obtained in O(1):

       take = prevRowSum[i+1]

   Instead of looping through every `j`.

7. The `skip` transition is:

       skip = dp[k][i+1]

   This means we don't start a segment at the current point and move to
   the next point.

8. Therefore:

       dp[k][i] = take + skip

   with modulo `M`.

9. Repeat this for every number of segments from 1 to K.

10. Finally:

       dp[K][0]

   gives the number of ways to create K non-overlapping line segments
   using all available points.

Key Idea:
---------
The main optimization is replacing the inner loop:

    for (int j = i + 1; j < n; j++)
        take += dp[k - 1][j];

with a precomputed suffix sum.

We store:

    prevRowSum[x]
        = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]

So:

    take = prevRowSum[i+1]

can be obtained in O(1).

This changes the transition from O(n) to O(1).

Therefore:

    Old DP:       O(K * n²)
    Optimized DP: O(K * n)

Example:
--------
Suppose we are calculating `dp[k][i]`.

The possible ways to take the next segment involve:

    dp[k-1][i+1]
    dp[k-1][i+2]
    dp[k-1][i+3]
    ...
    dp[k-1][n-1]

Instead of calculating this sum repeatedly, we precompute:

    prevRowSum[i+1]

which already contains the complete sum.

For example, if:

    dp[k-1] = [2, 3, 4, 5]

then:

    prevRowSum[3] = 5
    prevRowSum[2] = 4 + 5 = 9
    prevRowSum[1] = 3 + 4 + 5 = 12
    prevRowSum[0] = 2 + 3 + 4 + 5 = 14

So if `i = 1`:

    take = prevRowSum[2]
         = 9

instead of calculating:

    dp[k-1][2] + dp[k-1][3]

using another loop.

Time Complexity:
----------------
O(K * n)

For every value of `k`, we:
- Build `prevRowSum` in O(n).
- Calculate all `dp[k][i]` states in O(n).

Therefore:

    O(K * n)

Space Complexity:
-----------------
O(n²)

The `dp` array has dimensions:

    1001 × 1001

Additionally, `prevRowSum` uses O(n) temporary space.

The dominant space usage is therefore O(n²).
*/


                                       //MEMO - WILL GIVE TLE
// class Solution {
// public:
//     int M = 1e9 + 7;
//     int solve(int n, int k, int i, vector<vector<int>>& dp) {
//         if (k == 0)
//             return 1;

//         if (i >= n)
//             return 0;

//         if (dp[k][i] != -1)
//             return dp[k][i];

//         int take = 0;
//         for (int j = i + 1; j < n; j++) {
//             take = (take + solve(n, k - 1, j, dp)) % M;
//         }
//         int skip = solve(n, k, i + 1, dp) % M;
//         return dp[k][i] = (skip + take) % M;
//     }
//     int numberOfSets(int n, int k) {
//         vector<vector<int>> dp(k + 1, vector<int>(n, -1));
//         return solve(n, k, 0, dp);
//     }
// };
 
 
                                       //BOTTOM UP - WILL GIVE TLE
// class Solution {
// public:
//     int M = 1e9 + 7;
//     int dp[1001][1001];
//     int numberOfSets(int n, int K) {
//         for (int i = 0; i <= n; i++) {
//             dp[0][i] = (i < n) ? 1 : 0;
//         }
//         for (int k = 1; k <= K; k++) {
//             for (int i = n - 1; i >= 0; i--) {
//                 int skip = dp[k][i + 1];
//                 int take = 0;
//                 for (int j = i + 1; j < n; j++) {
//                     take = (take + dp[k - 1][j]) % M;
//                 }
//                 dp[k][i] = (take + skip) % M;
//             }
//         }
//         return dp[K][0];
//     }
// };
 
 
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];
    int numberOfSets(int n, int K) {
        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }
        for (int k = 1; k <= K; k++) {
            vector<int> prevRowSum(n + 1, 0);
            //prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }
            for (int i = n - 1; i >= 0; i--) {
                int skip = dp[k][i + 1];
                int take = prevRowSum[i+1];
                //dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]
                dp[k][i] = (take + skip) % M;
            }
        }
        return dp[K][0];
    }
};
