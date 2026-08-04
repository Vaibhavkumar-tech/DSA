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
    TreeNode* first;
    TreeNode* second;
    TreeNode* next_after_volation;
    TreeNode* prev;
    void Inorder(TreeNode* root){
        if(root==NULL) return;
        Inorder(root->left);
        if(prev!=NULL && prev->val>root->val){
            //voilation
            if(first==NULL){
                first=prev;
                next_after_volation=root;
            }
            else{
                second=root;
            }
        }
         prev=root;
        Inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        first=next_after_volation=second=NULL;
        Inorder(root);
        if(first && second) swap(first->val,second->val);
        else if(first && next_after_volation) swap(first->val,next_after_volation->val);
    }
 };