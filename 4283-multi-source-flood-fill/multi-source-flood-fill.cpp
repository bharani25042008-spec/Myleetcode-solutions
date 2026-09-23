class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
         vector<vector<int>>vis(n,vector<int>(m,0));
         vector<tuple<int,int,int>>s;
         for(auto it:sources){
              s.push_back({it[2],it[0],it[1]});
         }
         sort(s.begin(),s.end());
         reverse(s.begin(),s.end());
        for(auto it:s){
              auto[col,r,c]=it;
              grid[r][c]=col;
              vis[r][c]=1;
              q.push({col,r,c});
        } 

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
              auto[col,r,c]=q.front();
              q.pop();
              for(int i=0;i<4;i++){
                  int nr=r+dr[i];
                  int nc=c+dc[i];
                  if(nr>=n||nc>=m||nr<0||nc<0) continue;
                  if(vis[nr][nc]==1) continue;
                  vis[nr][nc]=1;
                  grid[nr][nc]=col;
                  q.push({col,nr,nc});
              }
        }
        return grid;
    }
};