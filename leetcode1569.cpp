/*
Problem:
---------
LeetCode 1569 - Number of Ways to Reorder Array to Get Same BST


Approach:
---------
The solution uses recursion and Pascal's Triangle to count the number of
ways to reorder the array while producing the same Binary Search Tree (BST).

1. Build Pascal's Triangle:
   We create a 2D vector `pt` where:

       pt[i][j] = C(i, j)

   This represents the number of ways to choose `j` elements from `i`
   elements.

   Each value is calculated using:

       C(i, j) = C(i - 1, j) + C(i - 1, j - 1)

   All calculations are performed modulo 10^9 + 7.

2. Construct the left and right subtrees:
   The first element of `nums` is the root of the BST.

   We traverse the remaining elements:
   - Values smaller than the root go into `leftarray`.
   - Values greater than the root go into `rightarray`.

3. Recursively calculate the number of valid reorderings:
   We call `solve()` for both subarrays to count the valid reorderings
   of the left and right subtrees.

4. Combine the results:
   Suppose the left subtree contains `L` elements and the right subtree
   contains `R` elements.

   The relative order of elements within each subtree must remain valid,
   but the left and right subtree elements can be interleaved.

   The number of ways to choose positions for the left subtree is:

       C(L + R, L)

   In the code, this is obtained using:

       pt[n - 1][leftarray.size()]

   Therefore, the total number of reorderings is:

       leftWays * rightWays * C(n - 1, L)

5. Exclude the original ordering:
   `solve()` counts the original ordering as one valid way.
   The problem asks for the number of other reorderings, so we subtract 1
   and normalize the result using modulo arithmetic.


Key Idea:
---------
The main observation is that the first element always becomes the root
of the BST.

For the resulting BST to remain the same:
- The elements belonging to the left subtree must preserve their relative
  ordering.
- The elements belonging to the right subtree must preserve their
  relative ordering.
- Left and right subtree elements can be interleaved in different ways.

For example, suppose:

    Left subtree elements  = [1, 2]
    Right subtree elements = [5, 6]

Their internal orders must remain unchanged, but they can be interleaved
while preserving the order within each group.

The number of ways to place the two left-subtree elements among the
remaining positions is:

    C(4, 2) = 6

The recursive calls count valid reorderings within each subtree, while
Pascal's Triangle counts how those two groups can be interleaved.

Finally:

    Answer = total ways - 1

The subtraction removes the original input ordering.


Example:
--------
Input:
nums = [2, 1, 3]

Step 1: Choose the root.

    Root = 2

Step 2: Split the remaining elements.

    Left subtree  = [1]
    Right subtree = [3]

Step 3: Count the subtree reorderings.

    Left ways  = 1
    Right ways = 1

Step 4: Interleave the subtrees.

There are two remaining positions, and we choose one for the left
subtree:

    C(2, 1) = 2

Therefore:

    Total ways = 1 * 1 * 2 = 2

Step 5: Exclude the original ordering.

    Answer = 2 - 1 = 1

Output:
    1


Time Complexity:
----------------
O(n^2) in the worst case.

Building Pascal's Triangle takes O(n^2) time.

The recursive BST construction can also take O(n^2) time in the worst
case because each recursive call scans its subarray to split its elements.

Therefore, the overall worst-case time complexity is O(n^2).


Space Complexity:
-----------------
O(n^2)

Pascal's Triangle stores O(n^2) values.

The recursive calls and the temporary left and right subarrays require
additional space, but the O(n^2) table dominates the overall space usage.
*/

class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    int solve(vector<int>& nums, vector<vector<ll>>& pt) {
        int n = nums.size();
        if (n < 3) {
            return 1;
        }
        vector<int> leftarray, rightarray;
        int root = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) {
                leftarray.push_back(nums[i]);
            } else {
                rightarray.push_back(nums[i]);
            }
        }
        ll x = solve(leftarray, pt);
        ll y = solve(rightarray, pt);
        ll z = pt[n - 1][leftarray.size()];
        return (((x * y) % MOD) * z) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> pt;
        pt.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            pt[i] = vector<ll>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                pt[i][j] = (pt[i - 1][j] + pt[i - 1][j - 1]) % MOD;
            }
        }
        return (solve(nums, pt) - 1 + MOD) % MOD;
    }
};
