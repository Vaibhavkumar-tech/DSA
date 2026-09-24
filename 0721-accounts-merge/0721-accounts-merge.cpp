class DisjointSet {
public:
    vector<int>parent,size;
    DisjointSet(int n) {
     parent.resize(n+1);
     size.resize(n+1,1);
     for(int i=0;i<=n;i++){
        parent[i]=i;
     }
    }
    int findUparent(int node) {
        if (parent[node] == node) return node; 
        return parent[node] = findUparent(parent[node]);
    }
    void unionBySize(int u, int v) {
     int u_parent=findUparent(u);
     int v_parent=findUparent(v);
     if(u_parent==v_parent) return;
     if(size[u_parent]>size[v_parent]){
        parent[v_parent]=u_parent;
        size[u_parent]+=size[v_parent];
     }
     else{
        parent[u_parent]=v_parent;
        size[v_parent]+=size[u_parent];
     }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mailNode;
        int n=accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mailNode.find(mail)==mailNode.end()){
                    //not found
                    mailNode[mail]=i;
                }
                else{
                    //found previously
                    ds.unionBySize(i,mailNode[mail]);
                }
            }
        }
        vector<vector<string>> MailMerged(n);
        for(auto it:mailNode){
            string mail = it.first;
            int idx = it.second;

            int parent = ds.findUparent(idx);

            MailMerged[parent].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(MailMerged[i].size()==0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(MailMerged[i].begin(), MailMerged[i].end());
            //iterate over mailmerged;
            for(auto it:MailMerged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};