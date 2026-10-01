/*
Problem:
---------
LeetCode 20 - Valid Parentheses


Approach:
---------
We use a stack to keep track of opening brackets.

While traversing the string:
- If the current character is an opening bracket `(`, `[`, or `{`,
  push it into the stack.
- If the current character is a closing bracket:
    - If the stack is empty, there is no opening bracket available to
      match it, so the string is invalid.
    - Otherwise, take the top opening bracket from the stack.
    - Compare it with the current closing bracket.
    - If they do not form a valid pair, return false.
    - If they match, remove the opening bracket from the stack.

After processing the complete string, the stack must be empty.
If anything remains, it means some opening brackets were never closed.


Key Idea:
---------
A stack follows LIFO (Last In, First Out).

This is exactly what we need for nested parentheses because the most
recently encountered opening bracket must be closed first.

Valid pairs are:
    '(' -> ')'
    '[' -> ']'
    '{' -> '}'

For every closing bracket, we compare it with the most recent opening
bracket stored at the top of the stack.

There are three invalid cases:
1. A closing bracket appears when the stack is empty.
2. The closing bracket does not match the top opening bracket.
3. Some opening brackets remain in the stack after traversal.


Example:
--------
Input:
s = "({[]})"

Process:
    '(' -> push
    '{' -> push
    '[' -> push
    ']' -> matches '[' -> pop
    '}' -> matches '{' -> pop
    ')' -> matches '(' -> pop

Stack becomes empty.

Result:
    true


Time Complexity:
----------------
O(n)

We traverse the string once, where n is the length of the string.


Space Complexity:
-----------------
O(n)

In the worst case, all characters can be opening brackets, so the stack
can contain up to n elements.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i =  0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if((s[i] == ')' && ch != '(') ||
                   (s[i] == ']' && ch != '[') ||
                   (s[i] == '}' && ch != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
