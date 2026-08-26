class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        deque<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        q.push_front({0,0});
        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};
        while(!q.empty()){
             auto [r,c]=q.front();
             q.pop_front();
             if(r==m-1&&c==n-1){
                  return dist[r][c];
             }
             for(int k=0;k<4;k++){
                 int nr=r+dr[k];
                 int nc=c+dc[k];
                 if(nr<0||nc<0||nr>=m||nc>=n){
                     continue;
                 }
                 int cost=0;
                 if(grid[r][c]==k+1){
                     cost=0;
                 }else{
                    cost=1;
                 }
                 int newdist=dist[r][c]+cost;
                 if(newdist<dist[nr][nc]){
                     dist[nr][nc]=newdist;
                     if(cost==0){
                     q.push_front({nr,nc});
                 }  else{
                    q.push_back({nr,nc});
                 }
                 }

             }
        }
        return dist[m-1][n-1];
    }
};