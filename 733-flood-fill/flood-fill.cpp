class Solution {
public:
void func(int i,int j,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,int src){
      if(i>=grid.size()||j>=grid[0].size()){
         return;
      }
      if(i<0||j<0){
         return;
      }
      if(vis[i][j]==1){
           return;
      }
      if(grid[i][j]==src){
         grid[i][j]=c;
      }
      vis[i][j]=1;
      if(i-1>=0){
      if(grid[i-1][j]==src)
        func(i-1,j,c,grid,vis,src);
      }
      if(i+1<grid.size()){
      if(grid[i+1][j]==src)
      func(i+1,j,c,grid,vis,src);
      }
      if(j+1<grid[0].size()){
      if(grid[i][j+1]==src)
      func(i,j+1,c,grid,vis,src);
      }
      if(j-1>=0){
        if(grid[i][j-1]==src)
      func(i,j-1,c,grid,vis,src);
      }
      vis[i][j]=0;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int m=image.size();
          int n=image[0].size();
          vector<vector<int>>vis(m,vector<int>(n,0));
          int src=image[sr][sc];
          func(sr,sc,color,image,vis,src);
          return image;
    }
};