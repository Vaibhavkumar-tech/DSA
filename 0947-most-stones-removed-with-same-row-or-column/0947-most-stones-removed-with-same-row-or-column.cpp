class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0;
        int maxCol = 0;

        // Find maximum row and column
        for (auto& it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Rows: 0 ... maxRow
        // Columns: maxRow+1 ... maxRow+maxCol+1
        DisjointSet ds(maxRow + maxCol + 2);

        unordered_map<int, int> stoneNodes;
        // Connect row with column
        for (auto& it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1;
            ds.unionBySize(row, col);

            // Store nodes that actually contain stones
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
        }

        // Count connected components
        int components = 0;
        for (auto& it : stoneNodes) {
            if (ds.findUParent(it.first) == it.first) {
                components++;
            }
        }
        return stones.size() - components;
    }
};