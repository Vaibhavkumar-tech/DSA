class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int originalcolor;
    void dfs(vector<vector<int>>& image, int sr, int sc, int color){
        if(sr>(image.size()-1 )|| sr<0 || sc>(image[0].size()-1) || sc<0) return ;
        if(image[sr][sc]==color || image[sr][sc]!=originalcolor) return ;
        image[sr][sc]=color;
        dfs(image, sr + dr[0], sc + dc[0], color);
        dfs(image, sr + dr[1], sc + dc[1], color);
        dfs(image, sr + dr[2], sc + dc[2], color);
        dfs(image, sr + dr[3], sc + dc[3], color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        originalcolor=image[sr][sc];
        dfs(image,sr,sc,color);
        return image;
    }
};