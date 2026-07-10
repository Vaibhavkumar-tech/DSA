class Solution {
public:
    vector<vector<int>> direction = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
        int freshCount=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    freshCount++;
                }
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        int min=0;
        if(freshCount==0) return 0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto it=q.front();
                q.pop();
                int i=it.first;
                int j=it.second;
                for(auto& dir:direction){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0 && new_j>=0 && new_i<row && new_j<col && grid[new_i][new_j]==1){
                        freshCount--;
                        grid[new_i][new_j]=2;
                        q.push({new_i,new_j});
                    }
                }
            }
            min++;
        }
        if(freshCount==0){
            return min-1;
        }
        return -1;
    }
};