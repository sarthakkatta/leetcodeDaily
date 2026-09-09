/*
Problem:
---------
LeetCode 3871. Count Commas in Range II

Approach:
---------
1. We don't iterate through every number from 0 to n.
   Instead, we group numbers based on how many commas they need.

2. Numbers from 1,000 to 999,999:
   - Have exactly 1 comma.

3. Numbers from 1,000,000 to 999,999,999:
   - Have exactly 2 commas.

4. Numbers from 1,000,000,000 to 999,999,999,999:
   - Have exactly 3 commas.

   And so on.

5. Start with:
       start = 1000
       commas = 1

   Here `start` represents the first number in the current group,
   while `commas` represents how many commas every number in that
   group contains.

6. Calculate the end of the current group:
       end = start * 1000 - 1

   For example:
       start = 1000
       end = 999999

   So this represents all 1-comma numbers.

7. Since `n` may fall somewhere inside the current range, use:
       till = min(n, end)

   This ensures we only count numbers up to n.

8. Number of values in the current group:
       till - start + 1

   Every one of these numbers contains `commas` commas, so:

       ans += (till - start + 1) * commas

9. Move to the next comma group:
       start *= 1000
       commas++

   This changes:
       1000 -> 1,000,000 -> 1,000,000,000 -> ...

10. Continue until `start > n`.

Key Idea:
---------
Instead of checking every number individually, count numbers in groups
having the same number of commas.

The ranges look like:

    1,000              -> 999,999          : 1 comma
    1,000,000          -> 999,999,999      : 2 commas
    1,000,000,000      -> 999,999,999,999  : 3 commas

For each range:

    count of numbers × commas per number

is added to the answer.

This reduces the complexity from O(n) to O(log₁₀(n)).

Example:
--------
n = 1,234,567

First group:

    start = 1,000
    end   = 999,999
    commas = 1

There are:

    999,999 - 1,000 + 1 = 999,000

numbers with 1 comma.

Contribution:

    999,000 × 1 = 999,000

Second group:

    start = 1,000,000
    end   = 999,999,999

But n = 1,234,567, so:

    till = 1,234,567

Number of values:

    1,234,567 - 1,000,000 + 1
    = 234,568

Each has 2 commas.

Contribution:

    234,568 × 2 = 469,136

Total:

    999,000 + 469,136
    = 1,468,136

Answer = 1,468,136.

Time Complexity:
----------------
O(log₁₀(n))

`start` is multiplied by 1000 in every iteration, so the number of
iterations is proportional to the number of digit groups in n.

Space Complexity:
-----------------
O(1)

Only a few variables are used.
*/

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        int commas = 1;
        while(start <= n){
            long long end = start * 1000 - 1;
            long long till =  min(n,end);
            ans += (till - start + 1) * commas;

            start *= 1000;
            commas++;
        }
        return ans;
    }
};
