class Solution {
public:
    vector<vector<int>> direction{
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };
    int m;
    int n;

    void DFS(int row,int col,vector<vector<char>>& board,vector<vector<int>>& visited){
        visited[row][col]=1;
        for(auto &dir:direction){
            int new_row=row+dir[0];
            int new_col=col+dir[1];
            if(new_row>=0 && new_row<m && new_col>=0 && new_col<n && visited[new_row][new_col]==0 && board[new_row][new_col]=='O'){
                DFS(new_row,new_col,board,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(); //row
        n = board[0].size(); //col
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(visited[0][i]==0 && board[0][i]=='O'){
                DFS(0,i,board,visited);
            }
            if(visited[m-1][i]==0 && board[m-1][i]=='O'){
                DFS(m-1,i,board,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(visited[i][0]==0 && board[i][0]=='O'){
                DFS(i,0,board,visited);
            }
            if(visited[i][n-1]==0 && board[i][n-1]=='O'){
                DFS(i,n-1,board,visited);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};