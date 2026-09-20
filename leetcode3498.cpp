/*
Problem:
---------
LeetCode 3498 - Reverse Degree of a String

Approach:
---------
1. Traverse the string from left to right using a 1-based index `i`.

2. For every character, calculate its reverse alphabetical value.

   Normal alphabetical positions are:

       a = 1
       b = 2
       c = 3
       ...
       z = 26

   Reverse alphabetical positions are:

       a = 26
       b = 25
       c = 24
       ...
       z = 1

3. The expression:

       123 - s[i - 1]

   calculates the reverse alphabetical value.

   This works because ASCII values are consecutive:

       'a' = 97
       'b' = 98
       ...
       'z' = 122

   Therefore:

       123 - 'a' = 26
       123 - 'b' = 25
       ...
       123 - 'z' = 1

4. Multiply the reverse alphabetical value by the character's
   1-based position:

       reverseValue × position

5. Add this contribution to `sum`.

6. After processing the complete string, return `sum`.

Key Idea:
---------
The reverse degree is the sum of:

    reverse alphabetical value × position

For every character:

    reverseValue = 123 - character

And because the problem uses 1-based positions:

    contribution = reverseValue × i

So:

    sum += (123 - s[i - 1]) × i

The important part is that `s[i - 1]` is used because the loop starts
from `i = 1`, while string indexing starts from 0.

Example:
--------
s = "abc"

Reverse alphabetical values:

    a -> 26
    b -> 25
    c -> 24

Positions:

    a -> 1
    b -> 2
    c -> 3

Therefore:

    Reverse Degree
    = 26 × 1 + 25 × 2 + 24 × 3
    = 26 + 50 + 72
    = 148

Answer = 148.

Example 2:
----------
s = "z"

Reverse value of `z`:

    123 - 'z'
    = 123 - 122
    = 1

Position = 1

Therefore:

    1 × 1 = 1

Answer = 1.

Time Complexity:
----------------
O(n)

Every character of the string is processed exactly once.

Space Complexity:
-----------------
O(1)

Only a few integer variables are used.
*/

class Solution {

public:

    int reverseDegree(string s) {

        int n = s.size();

        int sum = 0;

        for (int i = 1; i <= n; i++) {

            int diff = 123 - s[i - 1];

            sum += diff * i;

        }

        return sum;

    }

};
