class Solution {
public:

int n,m;
vector<vector<int>>dp;
int solve(vector<vector<int>>& grid,int i,int j){
    if(i>=m || j>=n || grid[i][j]==1) return 0;
    if(i==m-1 && j==n-1) return 1;

    //down 

    if(dp[i][j]!=-1) return dp[i][j];
    int down=solve(grid,i+1,j);
    int right=solve(grid,i,j+1);

    return dp[i][j]=right+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        this->m=m;
        this->n=n;
        dp.resize(m,vector<int>(n,-1));
        return solve(obstacleGrid,0,0);
    }
};