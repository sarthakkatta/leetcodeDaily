/*
Problem: LeetCode 3129 – Find All Possible Stable Binary Arrays I

Approach:
1. Use 3D Dynamic Programming:
   - dp[i][j][0] → arrays using i zeros and j ones ending with 0.
   - dp[i][j][1] → arrays using i zeros and j ones ending with 1.
2. Initialize base cases where only zeros or only ones are used within limit k.
3. For each state:
   - Add contributions from previous states.
   - Subtract invalid states where consecutive zeros or ones exceed k.
4. Use modulo (1e9 + 7) to handle large values.
5. Final answer = dp[zeros][ones][0] + dp[zeros][ones][1].

Time Complexity: O(zeros * ones)
Space Complexity: O(zeros * ones)
*/

class Solution{
public:
    int numberOfStableArrays(int zeros, int ones, int k){
        int mod = 1000000007;

        vector<vector<array<long long,2>>> dp(
            zeros + 1,
            vector<array<long long,2>>(ones + 1, {0, 0})
        );

        int mx = min(zeros, k);
        for(int i = 1; i <= mx; i++){
            dp[i][0][0] = 1;
        }

        mx = min(ones, k);
        for(int j = 1; j <= mx; j++){
            dp[0][j][1] = 1;
        }

        for(int i = 1; i <= zeros; i++){
            for(int j = 1; j <= ones; j++){

                long long cutZero = 0;
                long long cutOne = 0;

                if(i - k >= 1){
                    cutZero = dp[i - k - 1][j][1];
                }

                if(j - k >= 1){
                    cutOne = dp[i][j - k - 1][0];
                }

                long long addZero = dp[i - 1][j][0] + dp[i - 1][j][1];
                long long addOne  = dp[i][j - 1][0] + dp[i][j - 1][1];

                dp[i][j][0] = (addZero - cutZero + mod) % mod;
                dp[i][j][1] = (addOne - cutOne + mod) % mod;
            }
        }

        long long ans = dp[zeros][ones][0] + dp[zeros][ones][1];

        return ans % mod;
    }
};
