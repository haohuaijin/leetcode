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
    struct Status {
        int yes; // choose this node
        int no;  // don't choose this node
    };
    int rob(TreeNode* root) {
        auto status = dfs(root);
        return max(status.yes, status.no);
    }

    Status dfs(TreeNode* node){
        if(node == nullptr){
            return {0, 0};
        }
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int yes = node->val + l.no + r.no;
        int no = max(l.yes, l.no) + max(r.yes, r.no);
        return {yes, no};
    }
};
