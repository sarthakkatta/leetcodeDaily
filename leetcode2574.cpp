/*
Problem: LeetCode 2574 – Left and Right Sum Differences

Approach:
1. Create three arrays:
   - leftsum  → sum of elements to the left of each index
   - rightsum → sum of elements to the right of each index
   - res      → final answer
2. Compute left sums:
   - leftsum[0] = 0
   - leftsum[i] = leftsum[i-1] + nums[i-1]
3. Compute right sums:
   - rightsum[n-1] = 0
   - rightsum[i] = rightsum[i+1] + nums[i+1]
4. For every index:
   - res[i] = |leftsum[i] - rightsum[i]|
5. Return result array.

Key Idea:
- Precompute left and right prefix sums separately
  to efficiently calculate differences.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftsum(n);
        vector<int> rightsum(n);
        vector<int> res(n);

        leftsum[0] = 0;
        rightsum[n-1] = 0;

        for(int i = 1; i < n; i++){
            leftsum[i] = leftsum[i - 1] + nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--){
            rightsum[i] = rightsum[i + 1] + nums[i + 1];
        }

        for(int i = 0; i < n; i++){
            res[i] = abs(leftsum[i] - rightsum[i]);
        }

        return res;
    }
};
