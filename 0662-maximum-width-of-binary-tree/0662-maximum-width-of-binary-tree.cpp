class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long minId = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                long long curId = q.front().second - minId;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curId;
                if (i == size - 1) last = curId;

                if (node->left)
                    q.push({node->left, 2 * curId + 1});

                if (node->right)
                    q.push({node->right, 2 * curId + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};