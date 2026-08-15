/*
Problem: Longest Subsequence With Non-Zero Bitwise XOR

Approach:
1. First check if all elements of nums are 0.
   - If yes, XOR of every possible subsequence will be 0.
   - So the required answer is 0.
2. Calculate the XOR of all elements in nums.
3. If the total XOR is non-zero:
   - The complete array itself is a valid subsequence.
   - So answer = n.
4. If the total XOR is zero:
   - Since the array is not completely zero,
     there is at least one non-zero element.
   - Removing one suitable element can make the XOR non-zero.
   - Therefore answer = n - 1.

Key Idea:
- XOR of all elements tells whether the complete
  array can be used.
- If XOR is 0, we only need to remove one element.
- The all-zero case is handled separately because
  removing one element still leaves XOR = 0.

Example:

nums = [1, 2, 3]

XOR:
1 ^ 2 ^ 3 = 0

Since the array is not all zero,
we can remove one element.

Answer:
2

Another Example:

nums = [1, 2, 4]

XOR:
1 ^ 2 ^ 4 = 7

XOR is non-zero, so the complete array is valid.

Answer:
3

Time Complexity: O(N)

Space Complexity: O(N)
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int> zero(n, 0);
        if (nums == zero) {
            return 0;
        }
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x ? n : n - 1;
    }
};
