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
    int maxi=0;
    int Solve(TreeNode* root){
        if(root==NULL) return 0;
        int left=Solve(root->left);
        int right=Solve(root->right);
        maxi=max(maxi,right+left);
        return 1+max(right,left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Solve(root);
        return maxi;
    }
};