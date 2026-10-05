/*
Problem:
---------
LeetCode 856 - Score of Parentheses


Approach:
---------
We use a stack to keep track of the score accumulated outside the current
pair of parentheses.

The variable `score` stores the score of the current parentheses level.

Whenever we encounter an opening parenthesis `(`:
- Push the current `score` onto the stack.
- Reset `score` to 0 because we are entering a new nested level.

Whenever we encounter a closing parenthesis `)`:
There are two cases:

1. The previous character is `(`:
   This means we have found the simplest valid pair:

       ()

   According to the rules:

       () = 1

   So we add `1` to the score that was stored before entering this
   parentheses level:

       score = st.top() + 1

2. The previous character is `)`:
   This means the current parentheses contain another valid expression.

   According to the rules:

       (A) = 2 * A

   Therefore, the score of the current nested expression becomes:

       2 * score

   Then we add it to the score that existed before entering this level:

       score = st.top() + (2 * score)

In both cases, the previous score is removed from the stack using `pop()`.


Key Idea:
---------
The main idea is to calculate the score from the inside out.

The score rules are:

    () = 1

    AB = A + B

    (A) = 2 * A

The stack allows us to temporarily store the score of the outer level
while calculating the score of the inner parentheses.

For example:

    (()())

The inner `()` gives:

    1

The second `()` gives:

    1

So inside the outer parentheses:

    1 + 1 = 2

Then the outer parentheses double it:

    2 * 2 = 4

Therefore:

    (()()) = 4

The stack-based approach handles this nesting naturally by saving the
outer score whenever we encounter `(`.


Example:
--------
Input:
s = "(()())"

Processing:

    '(' -> push 0, score = 0
    '(' -> push 0, score = 0
    ')' -> "()" -> score = 1
    '(' -> push 1, score = 0
    ')' -> "()" -> score = 2
    ')' -> nested expression -> score = 4

Final answer:

    4


Time Complexity:
----------------
O(n)

We traverse the string once, where `n` is the length of the string.
Each character is processed only once.


Space Complexity:
-----------------
O(n)

In the worst case, the stack can contain indices/scores for every
nested opening parenthesis.
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int score = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            }else{
                if(s[i - 1] == '('){
                    score = st.top() + 1;
                    st.pop();
                }else{
                    score = st.top() + (2 * score);
                    st.pop();
                }
            }
        }
        return score;
    }
};
