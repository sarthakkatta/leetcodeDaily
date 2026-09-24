/*
Problem:
---------
LeetCode 3550 - Smallest Index With Digit Sum Equal to Index

Approach:
---------
1. Create a helper function `sumofdigit()`:
   - It calculates the sum of all digits of a given number.
   - Extract the last digit using:

       n % 10

   - Add it to `sum`.
   - Remove the last digit using:

       n /= 10

   - Continue until all digits are processed.

2. Traverse the array from left to right:
   - `i` represents the current index.
   - Calculate the digit sum of `nums[i]`.

3. Check whether:

       i == sumofdigit(nums[i])

   If true:
   - We found the smallest index satisfying the condition.
   - Since we are traversing from left to right, immediately return `i`.

4. If no index satisfies the condition:
   - Return -1.

Key Idea:
---------
For every index `i`, we only need to check one condition:

    index == sum of digits of nums[index]

The first index satisfying this condition is automatically the smallest
valid index.

The helper function calculates the digit sum by repeatedly taking the
last digit of the number.

Example:
--------
nums = [1, 3, 2, 6]

Index 0:
    nums[0] = 1
    digit sum = 1

    0 != 1
    Not valid.

Index 1:
    nums[1] = 3
    digit sum = 3

    1 != 3
    Not valid.

Index 2:
    nums[2] = 2
    digit sum = 2

    2 == 2
    Valid.

Therefore:

    Answer = 2

Example 2:
----------
nums = [10, 21, 12]

Index 0:
    digit sum of 10 = 1
    0 != 1

Index 1:
    digit sum of 21 = 3
    1 != 3

Index 2:
    digit sum of 12 = 3
    2 != 3

No valid index exists.

Answer = -1.

Time Complexity:
----------------
O(n × d)

where:
- `n` = number of elements.
- `d` = number of digits in the largest number.

For every element, we calculate its digit sum.

Space Complexity:
-----------------
O(1)

Only a few integer variables are used.
*/

class Solution {
public:
    int sumofdigit(int n) {
        int sum = 0;
        while (n > 0) {
            int ld = n % 10;
            sum += ld;
            n /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == sumofdigit(nums[i])) {
                return i;
            }
        }
        return -1;
    }
};
