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
    vector<vector<int>> levelOrder(TreeNode* root) {
        q.push({root,0});
        int level = -1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front.first == nullptr)
                continue;
            if(front.second > level){
                level++;
                res.emplace_back(vector<int>{});
            }
            res.back().emplace_back(front.first->val);
            q.push({front.first->left, front.second + 1});
            q.push({front.first->right, front.second + 1});
        }
        return res;
    }
private:
    queue<pair<TreeNode*,int>> q;
    vector<vector<int>> res;
};
