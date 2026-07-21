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
    TreeNode* Helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* RightlastnodeOfleftchild=find(root->left);
        RightlastnodeOfleftchild->right=rightchild;
        return root->left;
    }
    TreeNode* find(TreeNode* root){
        if(root->right==NULL) return root;
        return find(root->right);

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return Helper(root);
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left && root->left->val == key){
                    root->left=Helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right && root->right->val == key){
                    root->right=Helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
};