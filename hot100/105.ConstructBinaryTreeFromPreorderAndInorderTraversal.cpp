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
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            index[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& pre, vector<int>& in, int p1, int p2, int i1, int i2){
        if(p1 > p2){
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[p1]);
        // the index of root->val in inorder 
        int root_index = index[root->val];  
        // the len of left subtree
        int len = root_index - i1; 
        root->left = helper(pre, in, p1+1, p1+len, i1, root_index-1);
        root->right = helper(pre, in, p1+len+1, p2, root_index+1, i2);
        return root;
    }
};
