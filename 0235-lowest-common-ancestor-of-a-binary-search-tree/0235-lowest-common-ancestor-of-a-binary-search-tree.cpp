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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        int curr = root->val;

        // Both nodes are in the right subtree
        if (curr < p->val && curr < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // Both nodes are in the left subtree
        if (curr > p->val && curr > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // Split occurs here, so this is the LCA
        return root;
    }
};