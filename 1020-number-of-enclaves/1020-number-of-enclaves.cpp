class Solution {
public:

    int n;
    int m;
    vector<vector<int>>direction{{0,1},{0,-1},{1,0},{-1,0}};
    void DFS(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited){
        visited[i][j]=true;
        for(auto &dir:direction){
           int new_i=i+dir[0];
           int new_j=j+dir[1];
           if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && visited[new_i][new_j]==false && grid[new_i][new_j]==1){
              DFS(new_i,new_j,grid,visited);
           } 
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(); //rows
        n=grid[0].size(); //col
        vector<vector<int>>visited(m,vector<int>(n,false));
        for(int i=0;i<n;i++){
            if(visited[0][i]==false && grid[0][i]==1){
                DFS(0,i,grid,visited);
            }
            if(visited[m-1][i]==false && grid[m-1][i]==1){
                DFS(m-1,i,grid,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(visited[i][0]==false && grid[i][0]==1){
                DFS(i,0,grid,visited);
            }
            if(visited[i][n-1]==false && grid[i][n-1]==1){
                DFS(i,n-1,grid,visited);
            }
        }

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==false && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};