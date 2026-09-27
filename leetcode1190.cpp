/*
Problem:
---------
LeetCode 1190 - Reverse Substrings Between Each Pair of Parentheses

Approach:
---------
1. Use a stack of strings to keep track of the part that existed before
   entering the current pair of parentheses.

2. Maintain a string `current`:
   - It stores the characters currently being processed inside the
     innermost active parentheses.

3. When we encounter `(`:
   - Push the current string into the stack.
   - Reset `current` to an empty string.
   
   This starts processing the content inside the new parentheses.

4. When we encounter `)`:
   - The current string represents the content inside the parentheses.
   - Reverse it using:

       reverse(current.begin(), current.end())

   - The string stored at the top of the stack represents everything
     that existed before the opening `(`.
   - Add the reversed string after that previous part:

       current = st.top() + current

   - Remove that previous part from the stack.

5. When we encounter a normal character:
   - Simply append it to `current`.

6. After processing the complete string:
   - All parentheses have been handled.
   - `current` contains the final answer.

Key Idea:
---------
Whenever we encounter a pair of parentheses:

    (abc)

the content inside them must be reversed:

    (abc) -> cba

The stack helps us remember what was present before the opening
parenthesis.

For nested parentheses, the innermost pair is completed first because
its content is processed before the outer pair is closed.

Example:
--------
s = "(abcd)"

Initially:

    current = ""

After `(`:
    push ""
    current = ""

Read:
    a -> current = "a"
    b -> current = "ab"
    c -> current = "abc"
    d -> current = "abcd"

At `)`:

    reverse("abcd")
    = "dcba"

Then:

    current = "" + "dcba"
            = "dcba"

Answer:

    "dcba"

Example 2:
----------
s = "a(bc)de"

Read `a`:

    current = "a"

At `(`:
    push "a"
    current = ""

Read `bc`:

    current = "bc"

At `)`:

    reverse("bc") = "cb"

Then:

    current = "a" + "cb"
            = "acb"

Continue with `de`:

    current = "acbde"

Answer = "acbde"

Example 3:
----------
For nested parentheses:

    "(u(love)i)"

First process the inner part:

    (love) -> evol

So the string becomes conceptually:

    (uevoli)

Then reverse the outer parentheses:

    uevoli -> iloveu

Answer = "iloveu"

Time Complexity:
----------------
O(n²) in the worst case because reversing and concatenating strings can
take O(n) time, and these operations may happen multiple times for
nested parentheses.

Space Complexity:
-----------------
O(n)

The stack and strings together can store O(n) characters.
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";
        for(char c : s){
            if(c == '('){
                st.push(current);
                current = "";
            }else if(c == ')'){
                reverse(current.begin(), current.end());

                current = st.top() + current;
                st.pop();
            }else{
                current += c;
            }
        }
        return current;
    }
};
