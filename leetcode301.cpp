/*
Problem:
---------
LeetCode 301 - Remove Invalid Parentheses


Approach:
---------
We use Backtracking (Recursion) to generate all possible valid strings
after removing the minimum number of invalid parentheses.

First, we calculate exactly how many opening and closing parentheses
must be removed.

For every '(':
- Increase `left`.

For every ')':
- If there is an unmatched '(' available, match it by decreasing `left`.
- Otherwise, this ')' is invalid and must be removed, so increase `right`.

After this scan:
- `left` = minimum number of '(' that must be removed.
- `right` = minimum number of ')' that must be removed.

We then use the recursive `solve()` function to process every character.

For '(':
- We have two choices:
    1. Remove it if `left > 0`.
    2. Keep it and increase `balance`.

For ')':
- We have two choices:
    1. Remove it if `right > 0`.
    2. Keep it only if `balance > 0`, because a ')' can only be kept
       when there is an unmatched '(' available.

For normal characters:
- We always keep them because they do not affect parentheses validity.

When we reach the end of the string:
- `balance == 0` ensures all kept parentheses are properly matched.
- `left == 0` and `right == 0` ensure that exactly the required number
  of invalid parentheses have been removed.
- The resulting string is inserted into an `unordered_set` to avoid
  duplicate answers.


Key Idea:
---------
The main idea is to calculate the minimum number of invalid parentheses
that need to be removed first, instead of trying every possible number
of removals.

The `balance` variable represents the number of currently unmatched
opening parentheses.

Rules:
    '(' -> balance + 1
    ')' -> balance - 1

But a closing parenthesis is kept only when:

    balance > 0

This prevents the balance from ever becoming negative.

The first scan determines the exact removal counts:

    left  = extra '('
    right = extra ')'

Then the recursion explores only possibilities that remove exactly
those required parentheses.

The `unordered_set` is used because different removal paths can sometimes
produce the same resulting string.


Example:
--------
Input:
s = "()())()"

During the initial scan:
- There is one extra ')' that needs to be removed.
- So:

    left = 0
    right = 1

The recursion tries removing one invalid ')' while keeping the remaining
characters valid.

Possible valid results are:

    "()()()"
    "(())()"

Both require exactly one removal, so both are included in the answer.


Time Complexity:
----------------
O(2^n)

In the worst case, the recursion can explore multiple possibilities for
each parenthesis, resulting in exponential complexity.

The `unordered_set` also helps eliminate duplicate results.


Space Complexity:
-----------------
O(2^n)

The recursion can generate many possible strings, and the result set can
also contain exponentially many valid strings in the worst case.

Additionally, the recursion depth is O(n).
*/

class Solution {
public:
    void solve(string &s, int index, int left, int right, int balance, string curr, unordered_set<string> &ans) {
        if (balance < 0)
            return;

        if (index == s.size()) {
            if (balance == 0 && left == 0 && right == 0) {
                ans.insert(curr);
            }
            return;
        }
        // '('
        if (s[index] == '(') {
            // Remove '('
            if (left > 0) {
                solve(s, index + 1, left - 1, right, balance, curr, ans);
            }
            // Keep '('
            solve(s, index + 1, left, right, balance + 1, curr + '(', ans);
        }
        // ')'
        else if (s[index] == ')') {
            // Remove ')'
            if (right > 0) {
                solve(s, index + 1, left, right - 1, balance, curr, ans);
            }
            // Keep ')'
            if (balance > 0) {
                solve(s, index + 1, left, right, balance - 1, curr + ')', ans);
            }
        }
        // Normal character
        else {
            solve(s, index + 1, left, right, balance, curr + s[index], ans);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;
        for (char ch : s) {
            if (ch == '(') {
                left++;
            }
            else if (ch == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        unordered_set<string> temp;
        solve(s, 0, left, right, 0, "", temp);
        vector<string> ans(temp.begin(), temp.end());
        return ans;
    }
};
