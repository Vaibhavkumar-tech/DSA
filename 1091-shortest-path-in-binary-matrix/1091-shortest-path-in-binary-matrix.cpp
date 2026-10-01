class Solution {
public:
    vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         if(m==0 || n==0 || grid[n-1][m-1]==1 || grid[0][0]==1) return -1;
         queue<pair<int,int>>q;
         q.push({0,0});
         grid[0][0]=1;
         int level=1;
         while(!q.empty()){
            int N=q.size();
            while(N--){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                if(x==n-1 && y==m-1) return level;
                for(auto& dir:directions){
                    int new_x=x+dir[0];
                    int new_y=y+dir[1];
                    if(new_x<n && new_x>=0 && new_y>=0 && new_y<m && grid[new_x][new_y]==0){
                        grid[new_x][new_y]=1;
                        q.push({new_x,new_y});
                    }
                }
            }
            level++;
         }
         return -1;
    }
};