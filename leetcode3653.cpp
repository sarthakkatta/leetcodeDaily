/*
Problem: XOR After Queries (Custom)

Approach:
1. Iterate through each query:
   - Extract l, r, k, v from query.
   - For indices from l to r with step k:
     - Update nums[i] = (nums[i] * v) % mod
2. After processing all queries:
   - Compute XOR of all elements in nums.
3. Return the final XOR result.

Key Points:
- Use long long (1LL) to avoid overflow during multiplication.
- Modulo ensures values stay within limits.

Time Complexity:
- O(Q * (R-L)/K + N)

Space Complexity:
- O(1)
*/

class Solution {
public:
    const int mod = 1000000007;
    typedef long long ll;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for(int i = l; i <= r; i+= k){
                nums[i] = (1LL * nums[i] * v) % mod;
            }
        }
        int res = 0;
        for(int n : nums){
            res ^= n;
        }
        return res;
    }
};
