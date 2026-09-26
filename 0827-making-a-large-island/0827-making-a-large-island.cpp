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
    int getSize(int node) {
        int parentNode = findUParent(node);
        return size[parentNode];
    }
};

class Solution {
public: 
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int nr,int nc,int n){
        if(nr >= 0 && nr < n && nc >= 0 && nc < n ) return true;
        return false;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        //make parent-->no cell is connected 
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if(grid[r][c]==0) continue;
                for(auto& dir:directions){
                    int new_r=r+dir[0];
                    int new_c=c+dir[1];
                    if(isValid(new_r,new_c,n) && grid[new_r][new_c]==1){
                        int nodeNo=r*n+c;
                        int adjnodeNo=new_r*n+new_c;
                        ds.unionBySize(nodeNo,adjnodeNo);
                    }
                }
            }
        }

        int ans = 0;
        // Step 2: Try converting every 0 into 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) continue;
                set<int> components;
                for(auto& dir:directions){
                    int new_r = r + dir[0];
                    int new_c = c + dir[1];
                    if (isValid(new_r,new_c,n) && grid[new_r][new_c]==1) {
                        int adjNo = new_r * n + new_c;
                        int parent = ds.findUParent(adjNo);
                        components.insert(parent);
                    }
                }
                int totalsize=1; 
                for (int parent : components) {
                    totalsize+= ds.size[parent];
                }
                ans= max(ans, totalsize);
            }
        }

        // Step 3: If grid has no 0, or answer is still 0
        for (int i = 0; i < n * n; i++) {
            ans=max(ans,ds.getSize(ds.findUParent(i)));
        }
        return ans;
    }
};