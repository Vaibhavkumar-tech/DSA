class Solution {
public:
    int n,m;
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(i >= m || j >= n) {
            return 0;
        }

        if(grid[i][j]!=-1){
            return grid[i][j];
        }
        //down move
        int downSide=solve(grid,i+1,j);
        //right side
        int rightSide=solve(grid,i,j+1);
        return grid[i][j]=rightSide+downSide;
    }
    int uniquePaths(int m, int n) {
        this->m=m;
        this->n=n;
        //m*n
        vector<vector<int>>grid(m,vector<int>(n,-1));
        return solve(grid,0,0);
    }
};