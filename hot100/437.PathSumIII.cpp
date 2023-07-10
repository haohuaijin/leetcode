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
    int pathSum(TreeNode* root, int targetSum) {
        int res = helper(root, targetSum);
        if(root != nullptr){
            res += pathSum(root->left, targetSum);
            res += pathSum(root->right, targetSum);
        }
        return res;
    }
    int helper(TreeNode* root, long target){
        if(root == nullptr){
            return 0;
        } 
        int res = 0;
        if(root->val == target){
            res += 1;
        }

        res += helper(root->left, target - root->val);
        res += helper(root->right, target - root->val);
        return res;
    }
};
