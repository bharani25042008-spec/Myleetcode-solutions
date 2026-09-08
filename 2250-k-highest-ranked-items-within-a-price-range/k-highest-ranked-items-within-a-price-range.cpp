class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& prices, vector<int>& start, int k) {
         vector<tuple<int,int,int,int>>ans;
          queue<tuple<int,int,int,int>>q;
          vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
          vis[start[0]][start[1]]=1;
          q.push({0,0,start[0],start[1]});
          int dr[]={-1,1,0,0};
          int dc[]={0,0,-1,1};
          int l=prices[0];
          int h=prices[1];
          if(grid[start[0]][start[1]] >= l&&grid[start[0]][start[1]] <= h)
             {
                 ans.push_back({ 0,grid[start[0]][start[1]],start[0],start[1]});
             }
          while(!q.empty())
          {
              auto[dist,d,r,c]=q.front();
              q.pop();
              for(int i=0;i<4;i++){
                  int nr=r+dr[i];
                  int nc=c+dc[i];
                  if(nr>=grid.size()||nc>=grid[0].size()||nr<0||nc<0){
                     continue;
                  }
                  if(grid[nr][nc]==0) continue;
                  if(vis[nr][nc]==1) continue;
                 
                  if(grid[nr][nc]>=l&&grid[nr][nc]<=h){
                          ans.push_back({dist+1,grid[nr][nc],nr,nc});
                  }
                  vis[nr][nc]=1;
                  q.push({dist+1,grid[nr][nc],nr,nc});
              }
          }
        sort(ans.begin(),ans.end());
        if(ans.size()<k) {
            vector<vector<int>>res;
            for(auto [dist,d,r,c]:ans){
                     res.push_back({r,c});
           }
           return res;
        }
        vector<vector<int>>res;
        for(int i=0;i<k;i++){
            auto[dist,d,r,c]=ans[i];
            res.push_back({r,c});
        }
        return res;
    }
};