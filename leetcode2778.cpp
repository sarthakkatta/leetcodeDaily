/*
Problem:
---------
LeetCode 2778 - Sum of Squares of Special Elements


Approach:
---------
We first calculate the size of the array and store it in `n`.

Then, we traverse the array and check whether each element's 1-based
position divides the array size completely.

For an element at index `i`, its 1-based position is:

    i + 1

An element is considered special if:

    n % (i + 1) == 0

If this condition is true, we add the square of that element to `ans`:

    ans += nums[i] * nums[i]

After checking all elements, we return the final sum.


Key Idea:
---------
The important point is that the problem uses 1-based positions, while
C++ arrays use 0-based indexing.

Therefore:
- Index `0` represents position `1`.
- Index `1` represents position `2`.
- Index `2` represents position `3`.

We use `i + 1` to convert the array index into its 1-based position.

If the array size is divisible by that position, the element is special
and its square is included in the answer.


Example:
--------
Input:
nums = [1, 2, 3, 4]

Array size:
    n = 4

Checking each element:

    Index 0 -> Position 1
    4 % 1 == 0 -> Special
    Add 1 * 1 = 1

    Index 1 -> Position 2
    4 % 2 == 0 -> Special
    Add 2 * 2 = 4

    Index 2 -> Position 3
    4 % 3 != 0 -> Not special

    Index 3 -> Position 4
    4 % 4 == 0 -> Special
    Add 4 * 4 = 16

Final answer:

    1 + 4 + 16 = 21


Time Complexity:
----------------
O(n)

We traverse the array once, checking each element's position.


Space Complexity:
-----------------
O(1)

We use only a constant amount of extra space for variables.


Note:
-----
The loop condition in your original code is `i <= n`, which can access
`nums[n]` and cause an out-of-bounds error. The correct condition would
be `i < n`.

As requested, your original code below is preserved exactly as provided.
*/

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i <= n; i++){
            if((n % (i + 1)) == 0)ans += nums[i] * nums[i];
        }
        return ans;
    }
};
