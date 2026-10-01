class Solution {
public:
    vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(m==0 || n==0 || grid[n-1][m-1]==1 || grid[0][0]==1) return -1;
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int
        ,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        result[0][0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==n-1 && y==m-1) return dist;
            for(auto& dir:directions){
                int new_x=x+dir[0];
                int new_y=y+dir[1];
                int new_dist=dist+1;
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y] == 0 && new_dist<result[new_x][new_y]){
                    pq.push({new_dist,{new_x,new_y}});
                    result[new_x][new_y] = new_dist;
                }
            }

        }
        return -1;
    }
};