class Solution {
public:
    void solve(vector<vector<char>>& grid) {
          queue<pair<int,int>>q;
          int m=grid.size();
          int n=grid[0].size();
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||i==m-1||j==n-1)&&grid[i][j]=='O'){
                     grid[i][j]='*';
                     q.push({i,j});
                }
            }
          }
          int dr[]={-1,1,0,0};
          int dc[]={0,0,-1,1};
        while(!q.empty()){
              auto [r,c]=q.front();
              q.pop();
              for(int i=0;i<4;i++){
                  int nr=r+dr[i];
                  int nc=c+dc[i];
                  if(nr>=m||nc>=n||nr<0||nc<0){
                     continue;
                  }
                  if(grid[nr][nc]=='O'){
                    grid[nr][nc]='*';
                      q.push({nr,nc});
                  }
              }      
        }
        for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
             if(grid[i][j]=='O'){
                  grid[i][j]='X';
              }
          }
        }
        for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
             if(grid[i][j]=='*'){
                  grid[i][j]='O';
              }
          }
          }
    }
};