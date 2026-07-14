class Solution {
public:
    TreeNode* Solve(TreeNode* root){
        if(root==NULL) return NULL;

        TreeNode* leftHead = Solve(root->left);
        TreeNode* rightHead = Solve(root->right);

        root->left = NULL;
        root->right = leftHead;

        TreeNode* temp = root;
        while(temp->right){
            temp = temp->right;
        }

        temp->right = rightHead;

        return root;
    }

    void flatten(TreeNode* root) {
        Solve(root);
    }
};