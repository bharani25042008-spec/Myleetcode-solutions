class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
          priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
          int m=grid.size();
          int n=grid[0].size();
          vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
          dist[0][0]=0;
          q.push({0,0,0});
          int dr[]={-1,1,0,0};
          int dc[]={0,0,-1,1};
          while(!q.empty()){
             auto [val,r,c]=q.top();
             q.pop();
             if(r==m-1&&c==n-1)
             {
                 return val;
             }
             for(int i=0;i<4;i++){
                 int nr=r+dr[i];
                 int nc=c+dc[i];
                 if(nr>=m||nc>=n||nr<0||nc<0){
                     continue;
                 }
                 int diff=max(val,abs(grid[r][c]-grid[nr][nc]));
                 if(diff<dist[nr][nc]){
                     dist[nr][nc]=diff;
                     q.push({diff,nr,nc});
                 }
             }
          }
          return 0;
    }
};