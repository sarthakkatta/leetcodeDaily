/*
Problem: LeetCode 1563 – Stone Game V

Approach:
1. Use Dynamic Programming with a 2D dp array.
2. dp[i][j] stores the maximum score Alice can get
   from the subarray stoneValue[i...j].
3. Use Prefix Sum to calculate leftSum and rightSum
   quickly instead of calculating them again and again.
4. For every subarray, try every possible split position k:
      [i ... k] | [k+1 ... j]
5. If leftSum < rightSum:
   - Alice can only continue with the left part.
   - Add leftSum + dp[i][k].
6. If rightSum < leftSum:
   - Alice can only continue with the right part.
   - Add rightSum + dp[k+1][j].
7. If both sums are equal:
   - Alice can choose either side.
   - Take the maximum of both possibilities.
8. We calculate smaller subarrays first using:
      len = 2 → 3 → ... → n
   so that dp values required for bigger subarrays
   are already calculated.

Key Idea:
- Prefix Sum gives any subarray sum in O(1).
- dp[i][j] represents the best score Alice can get
  from that particular range.
- Every possible split is checked and the maximum
  possible score is stored.

Example:

stoneValue = [6, 2, 3, 4, 5, 5]

For a split:
[6] | [2,3,4,5,5]

leftSum = 6
rightSum = 19

Since leftSum < rightSum,
Alice gets 6 and continues with the left part.

For equal sums, Alice can choose either side.

Time Complexity: O(N^3)
- O(N^2) subarrays
- O(N) possible splits for each subarray

Space Complexity: O(N^2)
- prefix array → O(N)
- dp table → O(N^2)
*/

class Solution {
public:

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // Hum pehle chhote subarrays solve karenge,
        // phir bade subarrays.
        // len = 2  -> 2 elements ke subarrays
        // len = 3  -> 3 elements ke subarrays
        // ...
        // len = n  -> poora array
        // Ye important hai kyunki bade subarray ko solve
        // karte waqt humein chhote subarrays ka dp answer
        // already chahiye hoga.
        // ---------------------------------------------------
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) { // Current length ke har possible subarray ko choose kar rahe hain.
                int j = i + len - 1; // Ending index of current subarray
                for (int k = i; k < j; k++) { // used for harr possible subarray split
                    int leftSum = prefix[k + 1] - prefix[i];
                    int rightSum = prefix[j + 1] - prefix[k + 1];
                    if (leftSum < rightSum) { //leftpart is small
                        dp[i][j] = max(dp[i][j], leftSum + dp[i][k]);
                    }
                    else if (rightSum < leftSum) { //rightpart is small
                        dp[i][j] = max(dp[i][j],rightSum + dp[k + 1][j]);
                    }
                    else { //both parts are equal
                        dp[i][j] = max(dp[i][j],max(leftSum + dp[i][k],rightSum + dp[k + 1][j]));
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
