/*
Problem:
---------
LeetCode 1541 - Minimum Insertions to Balance a Parentheses String


Approach:
---------
We process the string from left to right and maintain:

    open = number of unmatched '('

    ans = number of insertions required so far

The important rule of this problem is that every opening parenthesis `(`
must be matched with exactly TWO consecutive closing parentheses:

    ()

Actually, one `(` requires:

    ())

So whenever we encounter `)` we need to make sure it has another `)`
after it.

For every `)`:

Step 1: Make a pair of `))`
--------------------------------
If the next character is already `)`, we use it as the second closing
parenthesis and skip it by doing:

    i++

Otherwise, the current `)` does not have a matching second `)`, so we
insert one:

    ans++

Step 2: Find a matching `(`
--------------------------------
After having a complete `))`, we need an opening `(` to match it.

If:

    open > 0

we already have an unmatched `(`, so we use it:

    open--

Otherwise, there is no opening parenthesis available, so we need to
insert one:

    ans++

At the end, some opening parentheses may still remain unmatched.

Each remaining `(` requires two `)` characters, so we add:

    open * 2

to the answer.


Key Idea:
---------
The key observation is that every `(` needs exactly:

    ())

Therefore, whenever we encounter a closing parenthesis, we first ensure
that it is part of a `))` pair.

For example:

    "(()))"

The first `(` creates an unmatched opening.
The second `(` creates another unmatched opening.
The `))` closes one of them.
The remaining `(` still needs two closing parentheses.

So the final unmatched opening contributes:

    2 insertions

The variable `open` keeps track of how many `(` are currently waiting
for their required `))`.

The final expression:

    ans + open * 2

handles all remaining unmatched opening parentheses.


Example:
--------
Input:
s = "(()))"

Processing:

    '('
        open = 1

    '('
        open = 2

    ')'
        Next character is ')' -> use both
        open > 0 -> match one '('
        open = 1

    ')'
        No second ')' available
        Insert one ')'
        ans = 1

        Match remaining '('
        open = 0

Final:

    ans = 1

So the answer is:

    1


Another Example:
----------------
Input:
s = "())"

Processing:

    '('
        open = 1

    ')'
        Next character is ')' -> use it
        open > 0 -> open = 0

The string is already balanced according to the required format:

    ()

Actually, the `(` is matched with `))`, so the two closing parentheses
complete the requirement.

Answer:

    0


Time Complexity:
----------------
O(n)

We traverse the string once. Although `i` is sometimes incremented inside
the loop, every character is processed at most once.


Space Complexity:
-----------------
O(1)

Only the variables `open` and `ans` are used, so the extra space is
constant.
*/

class Solution {
public:
    int minInsertions(string s) {
        int open = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else {
                // Step 1: make a "))"
                if (i + 1 < s.size() && s[i + 1] == ')') i++;
                else ans++;

                // Step 2: find its '('
                if (open > 0) open--;
                else ans++;
            }
        }
        return ans + open * 2;
    }
};
