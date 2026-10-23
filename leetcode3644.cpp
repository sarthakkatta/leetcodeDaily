/*
Problem:
---------
LeetCode 3644. Maximum K to Sort a Permutation


Approach:
---------
We initialize `k` to -1.

In a signed integer, -1 has all bits set to 1 in its binary representation
(using the usual two's-complement representation).

We traverse the array and check whether each element is already at its
correct index.

For an element at index `i`:
- If `nums[i] == i`, it is already in the correct position, so we ignore it.
- Otherwise, the element is misplaced, and we update `k` using bitwise AND:

      k &= nums[i]

The bitwise AND keeps only the bits that are set in both `k` and the
current misplaced value.

If `k` becomes 0, we return 0 immediately because no positive bitwise
AND value remains.

After processing all misplaced elements, we return:

      max(k, 0)

This ensures that the returned result is never negative.


Key Idea:
---------
The important observation is that we only consider elements that are
not at their correct indices.

For a permutation of numbers from 0 to n - 1, the required sorting
operation is governed by the bitwise AND of the misplaced elements.

Starting with:

      k = -1

allows the first misplaced element to initialize the effective bitwise
AND, because all bits of -1 are set.

For example:

      -1 & 6 = 6
      6 & 3 = 2
      2 & 1 = 0

Once the AND becomes 0, the result cannot become positive again by
ANDing with more values, so the function returns 0 immediately.

If no misplaced elements exist, `k` remains -1, and `max(k, 0)` returns 0.


Example:
--------
Input:
nums = [1, 0, 3, 2]

Check each index:

      i = 0 -> nums[0] = 1 != 0
              k = -1 & 1 = 1

      i = 1 -> nums[1] = 0 != 1
              k = 1 & 0 = 0

Since `k == 0`, the function immediately returns:

      0


Time Complexity:
----------------
O(n)

We traverse the array at most once, where n is the number of elements.


Space Complexity:
-----------------
O(1)

Only the integer variable `k` is used for additional storage.
*/

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1; //-1 isliye becoz Signed integer -1 ka binary representation mein saare bits 1 hote h
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i) { 
                k &= nums[i]; 
                if (k == 0) return 0; 
            }
        return max(k, 0); 
    }
};
