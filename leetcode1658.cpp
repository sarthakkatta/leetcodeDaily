/*
Problem:
---------
LeetCode 1658 - Minimum Operations to Reduce X to Zero cpp

Approach:
---------
1. Calculate the total sum of the array:

       totalSum = sum of all elements

2. We need to remove elements only from the left or right until their
   total sum becomes `x`.

3. Instead of directly finding the elements to remove, think about the
   part of the array that we want to KEEP.

   If:

       totalSum - removedSum = remainingSum

   and:

       removedSum = x

   then:

       remainingSum = totalSum - x

4. Therefore, the problem becomes:
   - Find the longest contiguous subarray whose sum is:

       totalSum - x

5. Why do we find the longest subarray?
   - If the longest subarray has length `maxlen`, then all elements
     outside this subarray can be removed from the two ends.
   - The number of removed elements will be:

       n - maxlen

   - Maximizing the kept subarray length minimizes the number of
     operations.

6. Use a sliding window:
   - `left` represents the beginning of the current window.
   - `right` expands the window one element at a time.
   - Add `nums[right]` to `sum`.

7. If:

       sum > remsum

   shrink the window from the left until:

       sum <= remsum

8. Whenever:

       sum == remsum

   we found a valid subarray.
   Update:

       maxlen = max(maxlen, right - left + 1)

9. Finally:
   - If no such subarray exists, return -1.
   - Otherwise return:

       n - maxlen

Key Idea:
---------
The important transformation is:

    Remove elements with sum x

becomes:

    Keep a subarray with sum totalSum - x

Since all numbers are positive, the sliding window works because:
- Expanding the right pointer increases the sum.
- Moving the left pointer decreases the sum.

We want the LONGEST valid subarray because everything outside it is
removed.

Therefore:

    Minimum Operations = n - Longest Valid Subarray Length

Example:
--------
nums = [1, 1, 4, 2, 3]
x = 5

Total sum:

    totalSum = 1 + 1 + 4 + 2 + 3
             = 11

Required remaining sum:

    remsum = totalSum - x
           = 11 - 5
           = 6

Now find the longest subarray having sum 6.

Possible subarray:

    [1, 1, 4]

Sum:

    1 + 1 + 4 = 6

Length = 3.

Therefore:

    n - maxlen
    = 5 - 3
    = 2

So the minimum number of operations is 2.

Example 2:
----------
nums = [5, 6, 7, 8, 9]
x = 4

Total sum = 35

Required remaining sum:

    35 - 4 = 31

There is no subarray with sum 31.

Therefore, it is impossible to reduce x to zero.

Answer = -1.

Time Complexity:
----------------
O(n)

The `right` pointer moves from left to right once, and the `left`
pointer also moves from left to right at most once.

Therefore, the total number of sliding-window operations is O(n).

Space Complexity:
-----------------
O(1)

Only a few variables are used.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalsum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalsum += nums[i];
        }
        if(totalsum - x < 0) return -1;
        int remsum = totalsum - x;
        int left = 0;
        int sum = 0;
        int maxlen = -1;
        for(int right = 0; right <nums.size(); right++){
            sum += nums[right];

        while(sum > remsum){
            sum -= nums[left];
            left++;
        }
        if(sum == remsum){
            maxlen = max(maxlen, right - left + 1);
        }
        }
        if(maxlen == -1) return -1;
        return n - maxlen;
    }
};
