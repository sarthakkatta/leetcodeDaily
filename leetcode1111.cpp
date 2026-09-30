/*
Problem:
---------
LeetCode 1111 - Maximum Nesting Depth of Two Valid Parentheses Strings


Approach:
---------
We need to divide the given valid parentheses sequence into two subsequences
such that the maximum nesting depth of the two subsequences is as small as
possible.

We keep track of the current nesting depth using the variable `curr`.

For every character:
- If it is '(':
    - Increase the current depth first.
    - Assign the parenthesis to group `curr % 2`.
- If it is ')':
    - Assign it to group `curr % 2` using the current depth.
    - Then decrease the current depth.

Using the parity (odd/even) of the current nesting depth distributes
nested parentheses between the two groups.

As a result, one group mainly receives parentheses at odd depths and the
other receives parentheses at even depths, preventing both groups from
having the full original nesting depth.


Key Idea:
---------
The important observation is that we don't need to explicitly calculate the
maximum depth of both groups.

At any point, the current nesting depth tells us how deeply nested we are.
By assigning parentheses based on `curr % 2`, consecutive nesting levels
are alternated between group 0 and group 1.

For '(':
    curr is increased before deciding the group.

For ')':
    the current depth is used to decide the group before decreasing curr.

This ensures that the nesting depth is balanced between the two groups.


Example:
--------
Input:
seq = "(()())"

Process:
    '(' -> curr = 1 -> ans = 1
    '(' -> curr = 2 -> ans = 0
    ')' -> curr = 2 -> ans = 0
    '(' -> curr = 2 -> ans = 0
    ')' -> curr = 2 -> ans = 0
    ')' -> curr = 1 -> ans = 1

Result:
    [1, 0, 0, 0, 0, 1]

Here, the parentheses are divided between the two groups based on the
parity of their nesting depth.


Time Complexity:
----------------
O(n)

We traverse the string exactly once, where n is the length of the
parentheses sequence.


Space Complexity:
-----------------
O(n)

The answer vector stores one group assignment for every character in
the input sequence.
*/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int curr = 0;
        vector<int> ans(seq.length());
        for (int i = 0; i < seq.length(); i++) {
            if (seq[i] == '(') {
                curr++;
                ans[i] = curr % 2;
            } else {
                ans[i] = curr % 2;
                curr--;
            }
        }

        return ans;
    }
};
