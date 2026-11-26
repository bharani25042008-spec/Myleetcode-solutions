class Solution {
public:
int dr[4]={1,-1,0,0};
int dc[4]={0,0,-1,1};
bool dfs(int i,int j,int pi,int pj,vector<vector<int>>&vis,vector<vector<char>>&grid,int m,int n){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=m||nc>=n||nr<0||nc<0){
                continue;
            }
            if(grid[nr][nc]!=grid[i][j]){
                continue;
            }
            if(vis[nr][nc]==1&&(nr!=pi||nc!=pj)){
                 return true;
            }
            if(vis[nr][nc]==0){
            if(dfs(nr,nc,i,j,vis,grid,m,n)){
                return true;
            }
            }
        }
        return false;
            
}
    bool containsCycle(vector<vector<char>>& grid) {
          int m=grid.size();
          int n=grid[0].size();
          vector<vector<int>>vis(m,vector<int>(n,0));
          for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                       if(vis[i][j]==0){
                       if(dfs(i,j,-1,-1,vis,grid,m,n)){
                           return true;
                       }
                       }
                  }
              }
          return false;
    }
};