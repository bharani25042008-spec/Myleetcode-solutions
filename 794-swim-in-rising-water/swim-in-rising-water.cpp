class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
          int n=grid.size();
          priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
          vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
          dist[0][0]=grid[0][0];
          q.push({grid[0][0],0,0});
          int dr[]={-1,1,0,0};
          int dc[]={0,0,-1,1};
          while(!q.empty()){
             auto[d,r,c]=q.top();
             q.pop();
             if(r==n-1&&c==n-1){
                 return d;
             }
             for(int i=0;i<4;i++){
                 int nr=r+dr[i];
                 int nc=c+dc[i];
                 if(nr<0||nc<0||nr>=n||nc>=n){
                     continue;
                 }
                 int nd=max(d,grid[nr][nc]);
                 if(nd<dist[nr][nc]){
                 dist[nr][nc]=nd;
                 q.push({nd,nr,nc});
                 }
             }
          }
        return 0;
    }
};