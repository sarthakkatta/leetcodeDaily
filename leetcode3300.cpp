/*
Problem: LeetCode 3300 – Minimum Element After Replacement With Digit Sum

Approach:
1. Create helper function `cal()`:
   - Compute sum of digits of a number.
2. Traverse the array:
   - Replace each number conceptually with its digit sum.
   - Track minimum digit sum encountered.
3. Store digit sums in result vector (optional as per code).
4. Return the minimum digit sum.

Key Idea:
- Convert every element into its digit sum and find the smallest one.

Time Complexity: O(N * D)
  (D = number of digits in an element)
Space Complexity: O(N)
*/

class Solution {
public:
    int cal(int n){
        int sum = 0;
        while(n > 0){
            int sing = n % 10;
            sum += sing;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        vector<int> res;
        int mini = INT_MAX;
        for(int n : nums){
            int sum = cal(n);
            mini = min(mini,sum);
            res.push_back(sum);
        }
        return mini;
    }
};
