/*
Problem: LeetCode 110 – Balanced Binary Tree

Approach:
1. Use DFS to calculate height of left and right subtrees.
2. If any subtree is already unbalanced, return -1.
3. If height difference > 1, mark tree as unbalanced.
4. Otherwise return current subtree height.
5. Tree is balanced if final DFS result is not -1.

Time Complexity: O(N)
Space Complexity: O(H)   // recursion stack, H = height of tree
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
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight , rightHeight) + 1; 
    }
};
