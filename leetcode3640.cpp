/*
Problem: Maximum Sum Trionic Subsequence

Approach:
1. Use DP with states: index + current trend.
2. Trend meanings:
   0 → not started
   1 → increasing
   2 → decreasing
   3 → increasing again (final phase)
3. At each index, either skip element or take it if it follows trend rules.
4. When trend reaches 3, we allow ending the sequence.
5. Use memoization to avoid recomputation.
6. Final answer starts from index 0 with trend = 0.

Time Complexity: O(N * 4)
Space Complexity: O(N * 4)
*/

class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> memo;

    ll solve(int i, int trend, vector<int>& nums) {
        if(i == n) {
            if(trend == 3) {
                return 0; //no more elements, you reached out of bound
            } else {
                return LLONG_MIN/2; //invalid small value
            }
        }

        if(memo[i][trend] != LLONG_MIN) {
            return memo[i][trend];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        //skip
        if(trend == 0) {
            skip = solve(i+1, 0, nums);
        }

        //i am at trend 3 and i can now end at nums[i]
        if(trend == 3) {
            take = nums[i]; //finish it here
        }

        if(i+1 < n) {
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && next > curr) {
                take = max(take, curr + solve(i+1, 1, nums));
            } else if(trend == 1) {
                if(next > curr) {
                    take = max(take, curr + solve(i+1, 1, nums));
                } else if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                }
            } else if(trend == 2) {
                if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                } else if(next > curr) {
                    take = max(take, curr + solve(i+1, 3, nums));
                }
            } else if(trend == 3 && next > curr) {
                take = max(take, curr + solve(i+1, 3, nums));
            }
        }
        
        return memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        memo.assign(n+1, vector<ll>(4, LLONG_MIN));
        return solve(0, 0, nums); //solve(i, trend = 0)
    }
};
