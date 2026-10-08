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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        int level = -1;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                if(q.front()){
                    if(res.size() <= level)
                        res.push_back(0);
                    res.back() = q.front()->val;
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }                
                q.pop();
            }
        }
        return res;
    }
};
