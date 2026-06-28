/*
Problem: Maximum Total Sum of K Selected Elements

Approach:
1. Sort the array in ascending order.
2. Start from the largest elements:
   - i = nums.size() - 1
3. Select exactly k elements.
4. For each selected element:
   - If multiplier (mul) is positive:
       contribution = nums[i] * mul
   - Otherwise:
       contribution = nums[i]
5. Add contribution to answer.
6. Move to the next largest element:
   - i--
   - mul--
7. Repeat until k elements are chosen.
8. Return the final sum.

Key Idea:
- Larger elements should receive larger multipliers.
- Sorting allows greedy selection from the end.

Time Complexity: O(N log N)
  (sorting dominates)

Space Complexity: O(1)
*/

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());

        int i = nums.size() - 1;
        long long ans = 0;

        while (k--) {
            if (mul > 0)
                ans += 1LL * nums[i] * mul;
            else
                ans += nums[i];

            i--;
            mul--;
        }

        return ans;
    }
};
