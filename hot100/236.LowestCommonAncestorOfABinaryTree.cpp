/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return res;
    }
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool left = helper(root->left, p, q);
        bool right = helper(root->right, p, q);
        if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right))) {
            res = root;
        } 
        return left || right || (root->val == p->val || root->val == q->val);
    }
};
