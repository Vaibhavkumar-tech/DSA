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

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (!reverse)
            pushAll(node->right);   // before
        else
            pushAll(node->left);    // next
        return node->val;
    }

private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if (!reverse)
                node = node->left;
            else
                node = node->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (!root) return false;

        BSTIterator left(root, false);   //next
        BSTIterator right(root, true);   // before
        int i = left.next();
        int j = right.next();
        while (i < j) {
            int sum = i + j;
            if (sum == k)
                return true;
            if (sum < k)
                i = left.next();  //give next element
            else
                j = right.next();  //give before element
        }
        return false;
    }
};