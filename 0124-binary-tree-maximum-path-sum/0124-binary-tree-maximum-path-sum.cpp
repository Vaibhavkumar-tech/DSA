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
    int maxi=INT_MIN;
    int MaxPath(TreeNode* root){
        if(root==NULL) return 0;
        int lSum=max(0,MaxPath(root->left));
        int rSum=max(0,MaxPath(root->right));
        maxi=max(maxi,lSum+rSum+root->val);
        return root->val+max(lSum,rSum);
    }
    int maxPathSum(TreeNode* root) {
        MaxPath(root);
        return maxi;
    }
};