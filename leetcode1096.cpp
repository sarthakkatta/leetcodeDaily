/*
Problem:
---------
LeetCode 1096 - Brace Expansion II

Approach:
---------
1. Use recursion to evaluate the expression inside braces.

2. There are two main operations in the expression:
   - Union `,`
   - Concatenation of different parts

3. `solve()` returns a `set<string>`:
   - The set automatically removes duplicate strings.
   - It also keeps the strings sorted lexicographically.

4. Maintain two sets inside `solve()`:
   - `current` -> all strings that can be formed by the expression
                  processed so far in the current concatenation.
   - `result`  -> final union of all comma-separated parts.

5. Initially:

       current = {""}

   The empty string is used as the starting point for concatenation.

6. When we encounter a normal character:
   - Convert it into a one-character string.
   - Put it into `temp`.
   - Combine `current` and `temp`.

   For example:

       current = {"a", "b"}
       temp = {"c"}

   Then:

       combine(current, temp)
       = {"ac", "bc"}

7. When we encounter `{`:
   - Move inside the braces recursively.
   - `solve()` evaluates the complete expression inside the braces.
   - Combine the result of the braces with `current`.

8. When we encounter `,`:
   - The current part is complete.
   - Add everything from `current` into `result`.
   - Reset `current` to `{""}` so the next comma-separated part can
     start independently.

9. When `}` is reached:
   - The current concatenation is finished.
   - Add the remaining strings in `current` into `result`.
   - Return `result` to the previous recursive call.

10. `combine()` performs Cartesian product:
    - Take every string from `a`.
    - Take every string from `b`.
    - Concatenate them.
    - Insert the result into a set.

11. Finally, `braceExpansionII()` calls `solve()` and converts the
    resulting set into a vector.

Key Idea:
---------
The whole expression can be thought of using two operations:

    Union:
        A , B

    Concatenation:
        A + B

For example:

    "{a,b}c"

The expression inside braces gives:

    {"a", "b"}

Then we concatenate `"c"` with every possibility:

    "a" + "c" = "ac"
    "b" + "c" = "bc"

So the result is:

    {"ac", "bc"}

The `combine()` function handles concatenation, while the `result`
and `current` sets handle union.

Example:
--------
expression = "{a,b}{c,d}"

First brace:

    {a,b} -> {"a", "b"}

Second brace:

    {c,d} -> {"c", "d"}

Now combine them:

    a + c = "ac"
    a + d = "ad"
    b + c = "bc"
    b + d = "bd"

Result:

    {"ac", "ad", "bc", "bd"}

Example 2:
----------
expression = "{a,b}c{d,e}"

First:

    {a,b} -> {"a", "b"}

Then concatenate `c`:

    {"ac", "bc"}

Then combine with:

    {d,e} -> {"d", "e"}

Final strings:

    "acd"
    "ace"
    "bcd"
    "bce"

So the answer is:

    {"acd", "ace", "bcd", "bce"}

Time Complexity:
----------------
Let `S` be the number of distinct strings generated.

The algorithm performs combinations of possible strings, so the
complexity depends on the number of generated expressions and their
lengths.

In the worst case, the number of generated strings can grow
exponentially with the number of choices.

The `set` operations additionally introduce logarithmic insertion cost.

Space Complexity:
-----------------
O(S × L)

where:
- `S` = number of distinct generated strings.
- `L` = maximum length of a generated string.

The sets store all distinct strings generated during the expansion.
*/

class Solution {
public:
    set<string> combine(set<string>& a, set<string>& b) {
        set<string> ans;
        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }
        return ans;
    }
    set<string> solve(string& expression, int& i) {
        set<string> result;
        set<string> current;
        current.insert("");
        while (i < expression.size() && expression[i] != '}') {
            if (expression[i] == ',') {
                // Union
                for (string x : current) {
                    result.insert(x);
                }

                current.clear();
                current.insert("");

                i++;
            }

            else if (expression[i] == '{') {
                i++;  // skip {

                set<string> inside = solve(expression, i);

                i++;  // skip }

                current = combine(current, inside);
            }

            else {
                // Normal character
                string ch(1, expression[i]);

                set<string> temp;
                temp.insert(ch);

                current = combine(current, temp);

                i++;
            }
        }
        // Add last part
        for (string x : current) {
            result.insert(x);
        }
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};
