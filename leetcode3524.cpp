/*
Problem:
---------
LeetCode : 3524. Find X Value of Array I

Approach:
---------
1. The main idea is Dynamic Programming based on the remainder of the
   product modulo `k`.

2. `dp[r]` stores the number of subarrays ending at the previous index
   whose product has remainder `r` when divided by `k`.

3. For every new element `x`, create a new array `curr`:
   - `curr[r]` stores the number of subarrays ending at the current
     index whose product has remainder `r`.

4. Start a new subarray using only the current element:

       curr[x % k]++

   This represents the subarray:

       [x]

5. Extend every previous subarray with the current element `x`.

   If a previous subarray has product remainder `r`, then after
   multiplying by `x`:

       newRemainder = (r * (x % k)) % k

   So:

       curr[newRemainder] += dp[r]

6. After calculating all subarrays ending at the current index:
   - Add every `curr[r]` to `ans[r]`.
   - `ans[r]` stores the total number of subarrays seen so far whose
     product has remainder `r`.

7. Finally, set:

       dp = curr

   because the current index becomes the previous index for the next
   iteration.

Key Idea:
---------
Instead of generating every subarray explicitly, we only remember the
remainder of its product modulo `k`.

For every element `x`:

    Previous remainder = r

    New remainder = (r × x) % k

This allows us to group many subarrays together based on their product
remainder.

`dp`:
    Subarrays ending at the previous index.

`curr`:
    Subarrays ending at the current index.

`ans`:
    Total subarrays having each possible remainder.

The important observation is that when a subarray is extended by `x`,
we only need its previous remainder, not its complete product.

Example:
--------
nums = [2, 3]
k = 3

Start:
    dp = [0, 0, 0]
    ans = [0, 0, 0]

Process x = 2:

    curr[2 % 3]++

    curr = [0, 0, 1]

So subarray:
    [2] -> product = 2 -> remainder = 2

Update:
    ans = [0, 0, 1]
    dp = [0, 0, 1]

Process x = 3:

Start a new subarray:

    [3]
    3 % 3 = 0

So:
    curr[0]++

Now extend the previous subarray:

    [2] -> [2, 3]

Previous remainder = 2

    newRemainder = (2 × 3) % 3
                  = 0

Therefore:

    curr[0] += dp[2]

Now `curr` represents:

    [3]     -> remainder 0
    [2,3]   -> remainder 0

And `ans` contains the total count of all subarrays grouped by
their product remainder.

Time Complexity:
----------------
O(n × k)

For every element, we loop through all `k` possible remainders.

Space Complexity:
-----------------
O(k)

We use three arrays of size `k`:

    dp
    curr
    ans
*/


// class Solution {
// public:
//     void solve(vector<int>& nums, int k, int i, long long product, vector<long long>& ans){
//         if(i == nums.size()) return;

//         product = (product * nums[i]) % k;

//         ans[product]++;
//         solve(nums,k, i + 1, product, ans);
//     }

//     vector<long long> resultArray(vector<int>& nums, int k) {
//         vector<long long> ans(k, 0);
//         int n = nums.size();

//         for(int i = 0; i < n; i++){
//             solve(nums,k,i,1,ans);
//         }
//         return ans;
//     }
// };
//


class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // Previous index par ending subarrays
        vector<long long> dp(k, 0);
        // Overall answer
        vector<long long> ans(k, 0);
        for(int x : nums) {
            // Current index par ending subarrays
            vector<long long> curr(k, 0);
            // Sirf current element ka subarray
            curr[x % k]++;
            // Previous subarrays ko current x ke saath extend karo
            for(int r = 0; r < k; r++) {
                int newRemainder = (r * (x % k)) % k;
                curr[newRemainder] += dp[r];
            }
            // Current index ke saare subarrays answer me add karo
            for(int r = 0; r < k; r++) {
                ans[r] += curr[r];
            }
            // Current ab next iteration ka previous ban jayega
            dp = curr;
        }
        return ans;
    }
};
