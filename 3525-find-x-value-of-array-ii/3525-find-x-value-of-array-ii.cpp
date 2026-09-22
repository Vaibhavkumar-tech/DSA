class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    vector<Node> seg;

    // Merge left and right node
    Node merge(Node left, Node right) {

        Node res;

        // Product of entire segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int i = 0; i < k; i++) {
            res.cnt[i] = left.cnt[i];
        }

        // Prefixes that cross into right
        for (int r = 0; r < k; r++) {

            int newRem = (left.prod * r) % k;

            res.cnt[newRem] += right.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {

        if (l == r) {

            int val = nums[l] % k;

            seg[node].prod = val;
            seg[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, int value) {

        if (l == r) {

            value %= k;

            seg[node] = Node();

            seg[node].prod = value;
            seg[node].cnt[value] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

        // Completely inside query range
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        // Only left side
        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        // Only right side
        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        // Both sides
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums,
                            int K,
                            vector<vector<int>>& queries) {

        k = K;

        int n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Query [start ... n-1]
            Node res = query(
                1,
                0,
                n - 1,
                start,
                n - 1
            );

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};