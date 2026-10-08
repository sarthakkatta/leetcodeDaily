/*
Problem:
---------
LeetCode 1021 - Remove Outermost Parentheses


Approach:
---------
We use a counter `cnt` to keep track of the current nesting depth of
parentheses.

The string is made up of one or more primitive valid parentheses strings.
For every primitive string, we need to remove its outermost `(` and `)`.

While traversing the string:

1. If the current character is `)`:
   - Decrease `cnt` first because we are moving one level up.

2. If `cnt != 0`:
   - The current character is not an outermost parenthesis, so we add it
     to the answer.

3. If the current character is `(`:
   - Increase `cnt` because we are entering one more nesting level.

The order is important:
- For `)`, we decrease the count before checking whether to add it.
- For `(`, we check the count before increasing it.

This automatically removes:
- An opening `(` when the current depth is 0.
- A closing `)` when it brings the depth back to 0.


Key Idea:
---------
The main idea is to identify the outermost level of every primitive
parentheses substring.

Consider:

    (()())

The first `(` takes the depth from 0 to 1. It is the outermost opening
parenthesis, so it should not be added.

The final `)` takes the depth from 1 to 0. It is the outermost closing
parenthesis, so it should also not be added.

Everything between them has a non-zero nesting depth and is included.

For example:

    (()())

After removing the outermost pair:

    ()()

The variable `cnt` represents the current nesting depth, allowing us to
identify exactly which parentheses belong to the outermost level.


Example:
--------
Input:
s = "(()())(())"

Primitive groups:

    (()())
    (())

Removing the outermost pair from each:

    ()()
    ()

Final answer:

    "()()()"


Time Complexity:
----------------
O(n)

We traverse the string exactly once, where `n` is the length of the
string.


Space Complexity:
-----------------
O(n)

The answer string can contain up to O(n) characters.
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                cnt--;
            }
            if(cnt != 0) {
                ans += s[i];
            }
            if(s[i] == '('){
                cnt++;
            }
        }
        return ans;
    }
};
