class Solution {
public:

/* int n,m;
vector<vector<int>>dp; */
/* int solve(vector<vector<int>>& grid,int i,int j){
    if(i<0 || j<0 || grid[i][j]==1) return 0;
    if(i==0 && j==0) return 1;

    //down 

    if(dp[i][j]!=-1) return dp[i][j];
    int down=solve(grid,i-1,j);
    int right=solve(grid,i,j-1);

    return dp[i][j]=right+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        this->m=m;
        this->n=n;
        dp.resize(m,vector<int>(n,-1));
        return solve(obstacleGrid,m-1,n-1);
    } */
 /*     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        this->m=m;
        this->n=n;
        dp.resize(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                    continue;
                };
                //down aa rha tha
                int down=0;
                int right=0;
                if(i>0){
                    down=dp[i-1][j];
                }
                //right se aa rha tha
                if(j>0){
                    right=dp[i][j-1];
                }

                dp[i][j]=right+down;
            }
        }
        return dp[m-1][n-1];
    } */
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j]=1;
                }
                else{
                    if(obstacleGrid[i][j] == 1) {
                        curr[j] = 0;
                    }
                    //down aa rha h
                    else{
                        int up=0;
                        int left=0;
                        if(i>0){
                            up=prev[j];
                        }
                        //right aa rha h
                        if(j>0){
                           left=curr[j-1];
                        }
                        curr[j] = up + left;
                    }
                }
                
            }
            prev=curr;
        }
        return prev[(n-1)];
    }
};