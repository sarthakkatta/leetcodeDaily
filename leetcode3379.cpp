/*
Problem: Construct Transformed Array

Approach:
1. For each index i, compute new index using (i + nums[i]) with modulo n.
2. Add +n before modulo to handle negative shifts safely.
3. Use formula: (i + (nums[i] % n) + n) % n to stay inside bounds.
4. Place nums[newIndex] into answer[i].

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0 ; i < n; i++){
            int idx = (i + (nums[i] % n) + n) % n;
            ans[i] = nums[idx];
        }

        return ans;
    }
};
