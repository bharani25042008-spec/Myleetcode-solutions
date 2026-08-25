class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<tuple<int,int,int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>vis(m,vector<vector<int>>(n,vector<int>(k+1,0)));
        vis[0][0][k]=1;
        q.push({0,0,k,1});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
             auto [r,c,rem,dist]=q.front();
             q.pop();
             if(r==m-1&&c==n-1){
                 return dist-1;
             }
             for(int i=0;i<4;i++){
                 int nr=r+dr[i];
                 int nc=c+dc[i];
                 int newrem=rem;
                 if(nr<0||nc<0||nr>=m||nc>=n){
                      continue;
                 }
                 if(grid[nr][nc]==1){
                    newrem--;
                 }
                 if(newrem<0){
                     continue;
                 }
                if(vis[nr][nc][newrem]==1){
                    continue;
                 }
                 vis[nr][nc][newrem]=1;
                 q.push({nr,nc,newrem,dist+1});

             }
             
        }
        return -1;
    }
};
