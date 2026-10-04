/*
Problem:
---------
LeetCode 678 - Valid Parenthesis String


Approach:
---------
We use two stacks to keep track of the positions of opening parentheses
and wildcard characters.

The two stacks are:

    openStack -> stores positions of '('
    starStack -> stores positions of '*'

The `*` character can act as:
    '('
    ')'
    or an empty character

While traversing the string:

1. If the character is '(':
   Push its index into `openStack`.

2. If the character is '*':
   Push its index into `starStack`.

3. If the character is ')':
   - First try to match it with an available '('.
   - If no '(' is available, use a '*' as a ')' instead.
   - If neither is available, the string is invalid.

After processing the complete string, there may still be unmatched
opening parentheses.

We can use remaining '*' characters to act as ')' and close them.

However, the order of positions is important:
- The '*' must appear AFTER the '(' that it is being used to close.
- If `*` occurs before the unmatched '(', it cannot be used to close it.

Therefore, while both stacks are non-empty, we compare their top indices.


Key Idea:
---------
The main idea is to treat `*` as a flexible character.

During the first traversal, whenever we encounter `)`:
- Prefer matching it with '('.
- If no '(' is available, use '*' as the required opening/matching
  character.
- If neither exists, return false.

For the remaining '(' characters, we need `*` characters that occur
after them.

For example:

    "( *"

can be valid because `*` can act as `)`.

But:

    "* ("

cannot use the `*` to close the `(` because the `*` appears before it.

That is why we check:

    openStack.top() < starStack.top()

If this condition is true, the '*' occurs after the '(' and can close it.


Example:
--------
Input:
s = "(*))"

Processing:

    '(' -> openStack = [0]
    '*' -> starStack = [1]
    ')' -> matches '(' at index 0
    ')' -> no '(' available, so '*' at index 1 is used

The string is valid.

Result:
    true


Another Example:
----------------
Input:
s = "*)("

Processing:
    '*' -> starStack = [0]
    ')' -> '*' is used as '('
    '(' -> openStack = [2]

Now the remaining '*' is at index 0, while '(' is at index 2.

Since:

    2 < 0

is false, the '*' occurs before the '(', so it cannot close it.

Result:
    false


Time Complexity:
----------------
O(n)

We traverse the string once, and the final matching loop processes each
stored index at most once.


Space Complexity:
-----------------
O(n)

In the worst case, all characters can be '(' or '*', so the two stacks
can contain up to O(n) elements.
*/

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack;  // positions of '('
        stack<int> starStack;  // positions of '*'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openStack.push(i);
            } 
            else if (s[i] == '*') {
                starStack.push(i);
            } 
            else if (s[i] == ')') {
                if (!openStack.empty()) {
                    openStack.pop();  // match with '('
                } 
                else if (!starStack.empty()) {
                    starStack.pop();  // match with '*'
                } 
                else {
                    return false;  // no match available
                }
            }
        }
        // match remaining '(' with '*' that come after them
        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() < starStack.top()) {
                openStack.pop();
                starStack.pop();
            } else {
                return false;  // '*' comes before '(', can't match
            }
        }
        return openStack.empty();
    }
};
