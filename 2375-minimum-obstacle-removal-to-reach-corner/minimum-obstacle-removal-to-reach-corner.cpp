class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
         deque<pair<int,int>>q;
         int m=grid.size();
         int n=grid[0].size();
         vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
         dist[0][0]=0;
         q.push_front({0,0});
         int dr[]={-1,1,0,0};
         int dc[]={0,0,-1,1};
         while(!q.empty()){
             auto [r,c]=q.front();
             q.pop_front();
             if(r==m-1&&c==n-1){
                 return dist[r][c];
             }
             for(int k=0;k<4;k++){
                 int nr=dr[k]+r;
                 int nc=dc[k]+c;
                 if(nr>=m||nc>=n||nr<0||nc<0){
                     continue;
                 }
                 if(dist[r][c]+grid[nr][nc]<dist[nr][nc]){
                     dist[nr][nc]=dist[r][c]+grid[nr][nc];
                     if(grid[nr][nc]==0){
                         q.push_front({nr,nc});
                     }else{
                        q.push_back({nr,nc});
                     }
                 }   
             }
         }
         return 0;
    }
};