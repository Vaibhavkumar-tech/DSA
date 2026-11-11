class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                //downside
                if(i==m-1 && j==n-1) continue;
                int downside=0;
                int rightside=0;
               if(i+1<m){
                downside=dp[i+1][j];
               }
               if(j+1<n){
                rightside=dp[i][j+1];
               }
               dp[i][j]=downside+rightside;
            }
        }
        return dp[0][0];
    }
};