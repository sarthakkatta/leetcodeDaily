/*
Problem: LeetCode 1022 – Sum of Root To Leaf Binary Numbers


Approach:
1. Use DFS traversal of the binary tree.
2. Maintain current binary number while traversing.
3. For each node, update current = current * 2 + node value.
4. If leaf node is reached, return current value.
5. Return sum of left and right subtree results.

Time Complexity: O(N)
Space Complexity: O(H)
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


class Solution{
public:
    int dfs(TreeNode* root, int current){
        if(root == NULL){
            return 0;
        }
        current = current * 2 + root->val;
        if(root->left == NULL && root->right == NULL){
            return current;
        }
        return dfs(root->left, current) + dfs(root->right, current);
    }

    int sumRootToLeaf(TreeNode* root){
        return dfs(root, 0);
    }
};
