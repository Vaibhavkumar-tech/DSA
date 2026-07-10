class Solution {
public:
    int DFS(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return 0;
        int ans=1;
        grid[i][j]=0;//visitedf
        ans+=DFS(grid,i-1,j);
        ans+=DFS(grid,i+1,j);
        ans+=DFS(grid,i,j-1);
        ans+=DFS(grid,i,j+1);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(row==0) return 0;
        int maxi=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int ans=DFS(grid,i,j);
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};