/*
Problem:
---------
LeetCode 1614 - Maximum Nesting Depth of the Parentheses

Approach:
---------
1. Maintain two variables:
   - `cur` -> current nesting depth.
   - `res` -> maximum nesting depth encountered so far.

2. Traverse the string character by character.

3. If the current character is `(`:
   - We enter one more level of nesting.
   - Increment `cur`.

       cur++

   - Update the maximum depth:

       res = max(cur, res)

4. If the current character is `)`:
   - We leave the current level of nesting.
   - Decrement `cur`.

       cur--

5. Characters other than parentheses are ignored because they do not
   affect the nesting depth.

6. After processing the entire string, return `res`.

Key Idea:
---------
The nesting depth at any point is simply the number of currently open
parentheses.

So:

    '(' -> depth increases by 1
    ')' -> depth decreases by 1

We keep track of the maximum value reached by `cur`.

Example:
--------
s = "(1+(2*3)+((8)/4))+1"

As we traverse:

    (       -> depth = 1
    (       -> depth = 2
    ((      -> depth = 3

The maximum depth reached is 3.

Therefore:

    Answer = 3

Example 2:
----------
s = "(1)+((2))+(((3)))"

The depths reached are:

    (1)       -> 1
    ((2))     -> 2
    (((3)))   -> 3

So:

    Answer = 3

Time Complexity:
----------------
O(n)

The string is traversed exactly once.

Space Complexity:
-----------------
O(1)

Only two integer variables are used.
*/

class Solution {

public:

    int maxDepth(string s) {

        int res = 0, cur = 0;

        for(char& c: s){

            if(c == '('){

                cur++;

                res = max(cur,res);

            }

            if(c == ')'){

                cur--;

            }

        }

        return res;

    }

};
