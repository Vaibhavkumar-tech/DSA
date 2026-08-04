/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class NodeValue {
public:
    bool isBST;
    int minNode;
    int maxNode;
    int sum;

    NodeValue(bool isBST, int minNode, int maxNode, int sum) {
        this->isBST = isBST;
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    NodeValue dfs(TreeNode* root) {
        if (root == NULL)
            return NodeValue(true, INT_MAX, INT_MIN, 0);

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.isBST && right.isBST &&
            left.maxNode < root->val &&
            root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return NodeValue(
                true,
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        return NodeValue(false, INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};