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
    bool isValidBST(TreeNode* root) {
        return isValidBSTRec(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTRec(TreeNode* root, int low, int high){
        if(root == nullptr) return true;
        int v = root->val;
        if(v > low && v < high){
            return isValidBSTRec(root->left, low, v) && isValidBSTRec(root->right, v, high);
        }
        return false;
    }
};
