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
    int goodNodes(TreeNode* root) {
        return goodNodesRec(root, -101);
    }

    int goodNodesRec(TreeNode* root, int maxi){
        if(root == nullptr) return 0;
        
        if(root->val >= maxi){
            maxi = root->val;
            
            return 1 + goodNodesRec(root->right, maxi) + goodNodesRec(root->left, maxi);
        }
        return 0 + goodNodesRec(root->right, maxi) + goodNodesRec(root->left, maxi);
    }
};
