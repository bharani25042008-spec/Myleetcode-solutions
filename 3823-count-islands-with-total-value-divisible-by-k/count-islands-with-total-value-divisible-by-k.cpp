class Solution {
public:
long long func(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
       if(i>=grid.size()||j>=grid[0].size()){
             return 0;
       }
       if(i<0||j<0){
             return 0;
       }
       if(grid[i][j]==0) return 0;
       if(vis[i][j]){
            return 0;
       }
       vis[i][j]=true;
       long long l=func(i,j-1,grid,vis);
       long long r=func(i,j+1,grid,vis);
       long long d=func(i+1,j,grid,vis);
       long long u=func(i-1,j,grid,vis);
       return (long long)grid[i][j]+l+r+d+u;
}
    int countIslands(vector<vector<int>>& grid, int k) {
           int m=grid.size();
           int n=grid[0].size();
           int ans=0;
           vector<vector<bool>>vis(m,vector<bool>(n,false));
           for(int i=0;i<m;i++)
           {
             for(int j=0;j<n;j++){
                  if(grid[i][j]!=0&&!vis[i][j]){
                      long long val=func(i,j,grid,vis);
                      if(val%k==0)  ans++;

                  }
             }
           }
           return ans;
    }
};