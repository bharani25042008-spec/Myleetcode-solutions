class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          queue<pair<int,int>>q;
          int m=image.size();
          int n=image[0].size();
          vector<vector<int>>vis(m,vector<int>(n,0));
          vis[sr][sc]=1;
          int src=image[sr][sc];
          image[sr][sc] = color;
          q.push({sr,sc});
          int dr[]={-1,1,0,0};
          int dc[]={0,0,-1,1};
          while(!q.empty()){
             auto [r,c]=q.front();
             q.pop();
             for(int k=0;k<4;k++){
                 int nr=r+dr[k];
                 int nc=c+dc[k];
                 if(nr>=image.size()||nc>=image[0].size()||nr<0||nc<0){
                    continue;
                 }
                 if(vis[nr][nc]==1){
                    continue;
                 }
                 if(image[nr][nc]!=src){
                   continue;
                 }
                    vis[nr][nc]=1;
                    image[nr][nc]=color;
                    q.push({nr,nc});
             }
          }
          return image;
    }
};