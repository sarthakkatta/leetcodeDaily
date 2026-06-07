/*
Problem: LeetCode 2196 – Create Binary Tree From Descriptions

Approach:
1. Use hashmap:
   - nodes[value] → TreeNode pointer.
2. Use a set to track all child nodes.
3. Traverse descriptions:
   - Create parent node if it doesn't exist.
   - Create child node if it doesn't exist.
   - Connect child as left or right child.
   - Mark child in children set.
4. After building tree:
   - Root is the node that never appears as a child.
5. Traverse all created nodes:
   - Return node not present in children set.
6. Return nullptr if no root found.

Key Idea:
- Every node except the root appears as a child exactly once.

Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if (!nodes.count(parent))
                nodes[parent] = new TreeNode(parent);

            if (!nodes.count(child))
                nodes[child] = new TreeNode(child);

            if (isLeft)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];

            children.insert(child);
        }

        for (auto &[value, node] : nodes) {
            if (!children.count(value))
                return node;
        }

        return nullptr;
    }
};
