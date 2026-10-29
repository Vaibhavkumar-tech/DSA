class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int n, timer;
    vector<int> tin, tout, eulerTour, segmentTree, depth;
    vector<vector<int>> ancestorTable;
    int cols;

    void dfs(int node, int parent, int d, string& s) {
        depth[node] = d;
        ancestorTable[node][0] = parent;

        tin[node] = timer;
        eulerTour[timer++] = 1 << (s[node] - 'a');

        for (int child : adj[node]) {
            if (child == parent) continue;
            dfs(child, node, d + 1, s);
        }

        tout[node] = timer;
        eulerTour[timer++] = 1 << (s[node] - 'a');
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        segmentTree[i] = segmentTree[2 * i + 1] ^ segmentTree[2 * i + 2];
    }

    void updateSegTree(int index, int val, int i, int l, int r) {
        if (l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
            updateSegTree(index, val, 2 * i + 1, l, mid);
        else
            updateSegTree(index, val, 2 * i + 2, mid + 1, r);

        segmentTree[i] = segmentTree[2 * i + 1] ^ segmentTree[2 * i + 2];
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        if (l > end || r < start) return 0;

        if (l >= start && r <= end) return segmentTree[i];

        int mid = l + (r - l) / 2;

        return querySegmentTree(start, end, 2 * i + 1, l, mid) ^
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r);
    }

    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                int parent = ancestorTable[node][j - 1];

                if (parent != -1)
                    ancestorTable[node][j] = ancestorTable[parent][j - 1];
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < cols; j++) {
            if (diff & (1 << j))
                u = ancestorTable[u][j];
        }

        if (u == v) return u;

        for (int j = cols - 1; j >= 0; j--) {
            if (ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        this->n = n;
        adj.clear();

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulerTour.assign(2 * n, 0);

        timer = 0;
        cols = log2(n) + 1;
        ancestorTable.assign(n, vector<int>(cols, -1));

        dfs(0, -1, 0, s);

        segmentTree.assign(8 * n, 0);
        buildSegmentTree(0, 0, 2 * n - 1, eulerTour);
        buildAncestorTable();

        vector<bool> result;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int node;
                char c;
                ss >> node >> c;

                int charValue = 1 << (c - 'a');
                s[node] = c;

                updateSegTree(tin[node], charValue, 0, 0, 2 * n - 1);
                updateSegTree(tout[node], charValue, 0, 0, 2 * n - 1);
            } else {
                int u, v;
                ss >> u >> v;

                int lcaNode = getLCA(u, v);
                int charValue = 1 << (s[lcaNode] - 'a');

                int mask = querySegmentTree(0, tin[u], 0, 0, 2 * n - 1) ^
                           querySegmentTree(0, tin[v], 0, 0, 2 * n - 1) ^
                           charValue;

                result.push_back((mask & (mask - 1)) == 0);
            }
        }

        return result;
    }
};