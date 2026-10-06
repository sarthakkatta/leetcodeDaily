/*
Problem:
---------
LeetCode 921 - Minimum Add to Make Parentheses Valid


Approach:
---------
We use two variables to keep track of unmatched parentheses:

- `size` keeps track of unmatched opening parentheses `(`.
- `open` keeps track of unmatched closing parentheses `)`.

While traversing the string:

1. If the current character is `(`:
   Increase `size` because we now have one more unmatched opening
   parenthesis.

2. If the current character is `)` and `size > 0`:
   There is an unmatched `(` available to match it, so decrease `size`.

3. Otherwise, the current character is `)` but there is no unmatched
   `(` available.
   This `)` itself needs an additional `(` before it, so increase `open`.

At the end:
- `open` = number of `(` that need to be added to match extra `)`.
- `size` = number of `)` that need to be added to match remaining `(`.

Therefore, the minimum number of additions required is:

    open + size


Key Idea:
---------
We don't need a stack because we only care about how many parentheses
remain unmatched.

For example:

    "())"

Processing:
    '(' -> size = 1
    ')' -> size = 0
    ')' -> no '(' available -> open = 1

At the end:

    open = 1
    size = 0

So we need to add one `(`:

    "())" -> "(()?)"

More simply, one opening parenthesis is required to balance the extra
closing parenthesis.

Similarly, for:

    "((("

we finish with:

    size = 3
    open = 0

So we need three `)` to make it valid.

The key observation is that every unmatched `)` requires one `(` to be
added, while every unmatched `(` requires one `)` to be added.


Example:
--------
Input:
s = "()))(("

Processing:

    '(' -> size = 1
    ')' -> size = 0
    ')' -> open = 1
    ')' -> open = 2
    '(' -> size = 1
    '(' -> size = 2

At the end:

    open = 2
    size = 2

Therefore:

    open + size = 4

So the minimum number of parentheses that need to be added is:

    4


Time Complexity:
----------------
O(n)

We traverse the string exactly once, where `n` is the length of the
string.


Space Complexity:
-----------------
O(1)

Only two integer variables are used, so the extra space is constant.
*/

class Solution {

public:

    int minAddToMakeValid(string s) {

        int size = 0;

        int open = 0;

        for(char ch : s){

            if(ch == '('){

                size++;

            }else if(size>0){

                size--;

            }else{

                open++;

            }

        }

        return open+size;

    }

};
