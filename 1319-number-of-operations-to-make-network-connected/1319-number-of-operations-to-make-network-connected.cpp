class DisjointSet {
public:
    vector<int>parent,rank;

    DisjointSet(int n) {
     parent.resize(n+1);
     rank.resize(n+1,0);
     for(int i=0;i<=n;i++){
        parent[i]=i;
     }
    }
    int findUparent(int node) {
        if (parent[node] == node) return node; 
        return parent[node] = findUparent(parent[node]);
    }

    void unionByRank(int u, int v) {
     int u_parent=findUparent(u);
     int v_parent=findUparent(v);
     if(u_parent==v_parent) return;
     if(rank[u_parent]>rank[v_parent]){
        parent[v_parent]=u_parent;
     }
     else if(rank[v_parent]>rank[u_parent]){
        parent[u_parent]=v_parent;
     }
     else{
        //equal
        parent[u_parent]=v_parent;
        rank[v_parent]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections){
            int a=it[0];
            int b=it[1];
            if(ds.findUparent(a)==ds.findUparent(b)){
                extra++;
            }
            else{
                ds.unionByRank(a,b);
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findUparent(i)==i) count++;
        }
        int ans=count-1;
        if(extra>=ans){
            return ans;
        }
        return -1;
    }
};