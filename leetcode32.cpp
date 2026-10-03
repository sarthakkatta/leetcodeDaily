/*
Problem:
---------
LeetCode 32 - Longest Valid Parentheses


Approach:
---------
We use a stack to store indices instead of storing the actual parentheses.

The stack initially contains `-1`, which acts as a base index. This helps
calculate the length of a valid parentheses substring when it starts from
index `0`.

While traversing the string:

1. If the current character is '(':
   - Push its index into the stack.
   - This index represents a possible starting point for a valid substring.

2. If the current character is ')':
   - Pop the top element because this closing parenthesis tries to match
     the most recent opening parenthesis.
   - If the stack becomes empty, it means there is no unmatched opening
     parenthesis available. The current index becomes the new base index,
     so we push `i`.
   - Otherwise, the stack top represents the index just before the current
     valid substring starts.
   - Therefore, the length of the current valid substring is:

       i - st.top()

   - We update `ans` with the maximum length found so far.


Key Idea:
---------
The most important idea is that the stack stores indices of unmatched
opening parentheses and the boundary positions of invalid substrings.

Initially:

    st.push(-1)

For a valid substring ending at index `i`, the top of the stack gives the
index immediately before that valid substring.

Therefore:

    length = i - st.top()

For example, for:

    s = "(()"

At the end:
- The valid substring is "()".
- Its starting boundary is index `0`.
- The closing parenthesis is at index `2`.

So:

    2 - 0 = 2

If the stack becomes empty after a closing parenthesis, that means the
current position cannot be part of a valid substring with anything before
it. We push the current index as the new boundary.


Example:
--------
Input:
s = ")()())"

Processing the string:

    ')' -> stack becomes empty -> push current index
    '(' -> push index
    ')' -> pop -> calculate valid length
    '(' -> push index
    ')' -> pop -> calculate valid length
    ')' -> stack becomes empty -> push current index

The longest valid substring is:

    "()()"

So the answer is:

    4


Time Complexity:
----------------
O(n)

We traverse the string once, where `n` is the length of the string.
Each index is pushed and popped from the stack at most once.


Space Complexity:
-----------------
O(n)

In the worst case, the stack can contain indices for all opening
parentheses.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }else{
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};
