/*
Problem:
---------
LeetCode 3870. Count Commas in Range

Approach:
---------
1. Initialize `ans = 0`:
   - This will store the total number of commas found across all numbers
     from 0 to n.

2. Traverse every number from 0 to n:
   - Convert the current number into a string using `to_string(i)`.
   - The length of the string tells us how many digits the number has.

3. Calculate the number of commas:
   - Every group of 3 digits after the first group requires a comma.
   - Therefore, for a number having `length` digits:

       (length - 1) / 3

     gives the number of commas required.

4. Add this value to `ans`:
   - This accumulates the commas required for every number from 0 to n.

5. Return `ans`.

Key Idea:
---------
The number of commas in a number depends only on its number of digits.

For example:

    123      -> 0 commas
    1234     -> 1 comma
    1234567  -> 2 commas
    1234567890 -> 3 commas

This can be calculated directly using:

    (number of digits - 1) / 3

Using integer division automatically gives the correct number of comma
groups.

Example:
--------
n = 1234

For numbers from 0 to 999:
    0 commas

For 1000 to 1234:
    Each number has 4 digits, so each needs 1 comma.

Therefore, the total answer is:

    1234 - 1000 + 1 = 235

Answer = 235.

Time Complexity:
----------------
O(n * d)

where `d` is the number of digits in the numbers.

For every number from 0 to n, we convert it into a string and calculate
its length.

Space Complexity:
-----------------
O(d)

The string created by `to_string()` uses space proportional to the
number of digits in the current number.
*/

class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for(int i = 0; i <= n; i++){
            string s = to_string(i);
            ans += (s.length() - 1)/ 3;
        }
        return ans;

    }

};
