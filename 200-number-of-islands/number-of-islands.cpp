class Solution {
public:
int func(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&vis){
        if(i>=grid.size()||j>=grid[0].size()) return 0;
        if(i<0||j<0) return 0;
        if(grid[i][j]=='0') return 0;
        if(vis[i][j]) return 0;
        vis[i][j]=true;
        int l=1+func(i,j-1,grid,vis);
        int r=1+func(i,j+1,grid,vis);
        int u=1+func(i-1,j,grid,vis);
        int d=1+func(i+1,j,grid,vis);
        return l+r+d+u;
}
    int numIslands(vector<vector<char>>& grid) {
            int ans=0;
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<bool>>vis(m,vector<bool>(n,false));
            for(int i=0;i<m;i++){
                 for(int j=0;j<n;j++){
                      if(grid[i][j]!='0'&&!vis[i][j]){
                            int val=func(i,j,grid,vis);
                            if(val>0) ans++;
                      }
                 }
            }
            return ans;
    }
};