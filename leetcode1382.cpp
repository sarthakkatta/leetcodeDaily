/*
Problem: LeetCode 1382 – Balance a Binary Search Tree

Approach:
1. Perform inorder traversal of BST to get sorted values.
2. Use the sorted array to build a balanced BST.
3. Choose middle element as root to keep tree height balanced.
4. Recursively build left and right subtrees.

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
    void inorder(TreeNode* node, vector<int>& value){
        if(!node) return;
        inorder(node->left, value);
        value.push_back(node->val);
        inorder(node->right, value);
    }

    TreeNode* construct(vector<int> & value, int left, int right){
        if(left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(value[mid]);

        node->left = construct(value, left, mid - 1);
        node->right = construct(value, mid + 1, right);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> value;
        inorder(root, value);
        return construct(value, 0, value.size() - 1);
    }
};
