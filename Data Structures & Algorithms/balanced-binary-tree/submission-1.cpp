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
        if(isBalancedRec(root) == -1) return false;
        return true;
    }

    int isBalancedRec(TreeNode* root){
        if(root == nullptr) return 0;
        auto left = isBalancedRec(root->left);
        auto right = isBalancedRec(root->right);
        if(left == -1 || right == -1) return -1;
        if(abs(left - right) >= 2) return -1;
        return 1 + max(right,left);
    }
};
