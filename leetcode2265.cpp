/*
Problem:
---------
LeetCode 2265 - Count Nodes Equal to Average of Subtree

Approach:
---------
1. Use DFS (Depth First Search) to traverse the binary tree.

2. For every node, recursively calculate:
   - `sum`   -> sum of all values in its subtree.
   - `count` -> total number of nodes in its subtree.

3. The DFS function returns:
       {sum, count}

   This allows the parent node to get the required information from
   both its left and right subtrees.

4. For the current node:

       sum = leftSum + rightSum + node->val
       count = leftCount + rightCount + 1

   The `+1` represents the current node.

5. Calculate the subtree average using integer division:

       sum / count

   If this average is equal to the current node's value, increment
   `answer`.

6. Return `{sum, count}` so that the parent node can use this
   information.

7. After the complete DFS, return `answer`.

Key Idea:
---------
For every node, instead of separately traversing its entire subtree,
we calculate the subtree's `sum` and `count` during the DFS itself.

For each node:

    Subtree Sum   = Left Sum + Right Sum + Node Value
    Subtree Count = Left Count + Right Count + 1

Then check:

    node->val == Subtree Sum / Subtree Count

If true, this node is counted.

Example:
--------
Consider:

        4
       / \
      8   5
     / \   \
    0   1   6

For node 0:
    sum = 0
    count = 1
    average = 0

So it is counted.

For node 1:
    sum = 1
    count = 1
    average = 1

So it is counted.

For node 8:
    sum = 8 + 0 + 1 = 9
    count = 3
    average = 9 / 3 = 3

Since 8 != 3, it is not counted.

The same process is performed for every node.

Time Complexity:
----------------
O(n)

Every node is visited exactly once.

Space Complexity:
-----------------
O(h)

where `h` is the height of the binary tree.

The recursive DFS uses O(h) stack space.
For a balanced tree, this is O(log n).
For a skewed tree, this can be O(n).
*/

class Solution {

    int answer = 0;

    pair<int, int> dfs(TreeNode* node) {

        if (node == nullptr) {

            return {0, 0};

        }

        auto [leftSum, leftCount] = dfs(node->left);

        auto [rightSum, rightCount] = dfs(node->right);

        int sum = leftSum + rightSum + node->val;

        int count = leftCount + rightCount + 1;

        if (node->val == sum / count) {

            answer++;

        }

        return {sum, count};

    }

public:

    int averageOfSubtree(TreeNode* root) {

        dfs(root);

        return answer;

    }

};
