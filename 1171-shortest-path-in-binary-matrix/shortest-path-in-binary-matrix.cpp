class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1){
             return -1;
        }
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<tuple<int,int,int>>q;
        q.push({0,0,1});
        vis[0][0]=1;
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
           auto [r,c,dist]=q.front();
           q.pop();
           if(r==n-1&&c==n-1){
                return dist;
           }
           for(int k=0;k<8;k++){
             int nr=r+dr[k];
             int nc=c+dc[k];
             if(nr>=n||nc>=n||nr<0||nc<0){
                 continue;
             }
             if(vis[nr][nc]==1){
                 continue;
             }
             if(grid[nr][nc]==1){
                   continue;
             }
             vis[nr][nc]=1;
             q.push({nr,nc,dist+1});
           }
        }
    return -1;
    }
};