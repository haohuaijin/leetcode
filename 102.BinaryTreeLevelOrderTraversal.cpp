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
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            res.push_back(vector<int>());
            for (int i = 1; i <= len; ++i) {
                TreeNode* tmp = q.front(); 
                q.pop();
                res.back().push_back(tmp->val);
                if(tmp->left) 
                    q.push(tmp->left);
                if(tmp->right) 
                    q.push(tmp->right);
            }
        }
        
        return res;
    }
};

