/*
Problem:
---------
LeetCode 22 - Generate Parentheses


Approach:
---------
We use Backtracking (Recursion) to generate all possible combinations
of `n` pairs of valid parentheses.

We keep track of two counts:
- `oc` = number of opening parentheses `(` used.
- `cc` = number of closing parentheses `)` used.

At every recursive call, we have two possible choices:

1. Add an opening parenthesis:
   We can add `(` as long as `oc < n`.

2. Add a closing parenthesis:
   We can add `)` only when `cc < oc`.

The second condition is very important because it ensures that we never
create an invalid parentheses sequence where a closing parenthesis comes
before its corresponding opening parenthesis.

When:
    oc == n && cc == n

we have used all `n` opening and `n` closing parentheses, so the
constructed string is a valid answer and we add it to the result vector.


Key Idea:
---------
The main idea is to build the answer character by character while always
maintaining the validity of the parentheses sequence.

For opening parentheses:
    oc < n

means we still have some `(` available to use.

For closing parentheses:
    cc < oc

means we can only add `)` if there is an unmatched `(` available.

For example, we can have:

    "("
    "(("
    "(()"

but we can never create:

    ")"
    "())"

because `cc < oc` would not be satisfied.

This automatically removes invalid combinations during recursion instead
of generating all combinations first and checking them later.

The recursion explores both possible choices whenever they are valid,
which generates every valid parentheses combination.


Example:
--------
Input:
n = 3

Some recursive paths are:

    ""
     |
     (
     |
    ((
     |
    (((
     |
    ((()
     |
    ((())
     |
    ((()))

Another valid sequence generated is:

    (()())
    (())()
    ()(())
    ()()()

Final result contains all valid combinations:

    ["((()))", "(()())", "(())()", "()(())", "()()()"]


Time Complexity:
----------------
O(4^n / sqrt(n))

There are Catalan number of valid combinations:

    C(n) = (1 / (n + 1)) * C(2n, n)

which is approximately O(4^n / n^(3/2)).

Since every generated string has length 2n, the overall work is commonly
described in terms of the Catalan number multiplied by the output size.


Space Complexity:
-----------------
O(n)

The recursion depth can reach 2n, and the current string can also contain
up to 2n characters.

Apart from the output, the auxiliary recursion space is O(n).
*/

class Solution { 
    public: 
    void helper( vector<string> &v, int n, int oc, int cc, string s){ 
        if(oc == n && cc == n){ 
            v.push_back(s); 
            return; 
        } 
        if(oc < n){ 
            helper(v,n,oc + 1,cc,s + "("); 
        } 
        if(cc < oc){ 
            helper(v,n,oc,cc + 1,s + ")"); 
        } 
    } 
public: 
    vector<string> generateParenthesis(int n) { 
        vector<string> v; 
        int oc = 0, cc = 0; 
        helper(v,n,oc,cc,""); 
        return v; 
    } 
};
