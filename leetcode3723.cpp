/*
Problem:
---------
LeetCode 3723. Maximize Sum of Squares of Digits


Approach:
---------
First, we check whether the required digit sum is possible.

Every decimal digit can have a maximum value of 9. Therefore, the maximum
possible sum for `num` digits is:

    9 * num

If `sum > 9 * num`, it is impossible to construct a number with the
required number of digits, so we return an empty string.

Otherwise, we construct the answer from left to right.

At every position:
- Choose the largest possible digit, which is `min(9, sum)`.
- Append that digit to `ans`.
- Subtract the chosen digit from `sum`.
- Decrease `num` because one position has been filled.

After all positions are filled:
- If `sum == 0`, all the required sum has been used, so we return `ans`.
- Otherwise, the required sum could not be distributed across the given
  number of digits, so we return an empty string.


Key Idea:
---------
The main idea is to greedily place the largest possible digit at every
position.

The expression:

    min(9, sum)

ensures that:
- No digit is greater than 9.
- We never assign more than the remaining required sum.

For example, if `sum = 23`, the digits selected are:

    9 -> remaining sum = 14
    9 -> remaining sum = 5
    5 -> remaining sum = 0

This produces:

    "995"

However, the algorithm must still check whether all the required sum
has been used after filling exactly `num` positions.


Example:
--------
Input:
num = 3
sum = 20

Initially:
    ans = ""
    sum = 20
    num = 3

First iteration:
    digit = min(9, 20) = 9
    ans = "9"
    sum = 11
    num = 2

Second iteration:
    digit = min(9, 11) = 9
    ans = "99"
    sum = 2
    num = 1

Third iteration:
    digit = min(9, 2) = 2
    ans = "992"
    sum = 0
    num = 0

Since the remaining sum is 0, we return:

    "992"


Time Complexity:
----------------
O(num)

The loop executes exactly `num` times, and each iteration performs
constant-time operations, excluding string allocation overhead.


Space Complexity:
-----------------
O(num)

The resulting string stores exactly `num` digits when a valid answer
exists.
*/

class Solution {

public:

    string maxSumOfSquares(int num, int sum) {

        // Step 1: the biggest possible digit sum is 9 * num

        if (sum > 9 * num) return "";

        string ans;

        // Step 2: fill every position from left to right

        while (num > 0) {

            int digit = min(9, sum);   // take as much as we can, at most 9

            ans += char('0' + digit);

            sum -= digit;

            num--;

        }

        return sum == 0 ? ans : "";

    }

};
