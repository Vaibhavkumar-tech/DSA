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
    bool Solve(TreeNode* left ,TreeNode* right){
        if(left==NULL || right==NULL) return right==left;
        if(left->val!=right->val) return false;
        return Solve(left->left,right->right) && Solve(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return Solve(root->left,root->right);
    }
};