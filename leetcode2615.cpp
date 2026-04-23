/*
Problem: 2615. Sum of Distances

Approach:
1. Group indices of same elements using hashmap:
   - mp[value] → list of positions where it appears.
2. For each group:
   - Compute total sum of indices.
3. Iterate through positions:
   - Maintain leftSum (sum of indices to the left).
   - Compute rightSum = totalSum - leftSum - current index.
4. For each position:
   - Left contribution  = pos[i] * i - leftSum
   - Right contribution = rightSum - pos[i] * (m - i - 1)
5. Total distance = left + right.
6. Store result at corresponding index.

Key Idea:
- Prefix sums allow efficient calculation of distances.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        for(auto &it : mp){
            auto &pos = it.second;

            long long sum = 0;
            for(int x : pos) sum += x;

            long long leftSum = 0;
            int m = pos.size();

            for(int i = 0; i < m; i++){
                long long rightSum = sum - leftSum - pos[i];

                long long left  = 1LL * pos[i] * i - leftSum;
                long long right = rightSum - 1LL * pos[i] * (m-i-1);

                ans[pos[i]] = left + right;

                leftSum += pos[i];
            }
        }

        return ans;
    }
};
