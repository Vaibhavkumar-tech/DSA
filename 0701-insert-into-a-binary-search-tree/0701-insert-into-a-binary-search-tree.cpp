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
    TreeNode* insertIntoBST(TreeNode* root, int target) {
        TreeNode* newNode=new TreeNode(target);     //heap mein bna diya
        if(root==NULL){
            return newNode;
        }
        TreeNode* curr=root;
        while(curr!=NULL){
            if(target<curr->val){
                if(curr->left!=NULL){
                    curr=curr->left;
                }
                else{
                    curr->left=newNode;
                    break;
                }
            }
            else{
                if(curr->right!=NULL){
                    curr=curr->right;
                }
                else{
                    curr->right=newNode;
                    break;
                }
            }
        }
        return root;
    }
};