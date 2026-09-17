class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(n,vector<int>(2,0)));
        vis[0][0][0]=1;
        
        queue<tuple<int,int,int,int,int,int>>q;
        q.push({0,0,0,0,1,0});
        while(!q.empty()){
            auto[d,r1,c1,r2,c2,dir]=q.front();
            q.pop();
            if(r1==n-1&&c1==n-2&&r2==n-1&&c2==n-1){
                   return d;
            }
            if(c1+1<n&&grid[r1][c1+1]==0&&c2+1<n&&grid[r2][c2+1]==0){
                 if(vis[r1][c1+1][dir]==0){
                    vis[r1][c1+1][dir]=1;
                     q.push({d+1,r1,c1+1,r2,c2+1,dir});
                 }
            }
            if(r1+1<n&&grid[r1+1][c1]==0&&r2+1<n&&grid[r2+1][c2]==0){
                if(vis[r1+1][c1][dir]==0){
                vis[r1+1][c1][dir]=1;
                q.push({d+1,r1+1,c1,r2+1,c2,dir});
                }
            }
            if(dir==0){
                if(r1+1<n&&grid[r1+1][c1]==0&&r2+1<n&&grid[r2+1][c2]==0){
                    if(vis[r1][c1][1]==0){
                    vis[r1][c1][1]=0;
                    q.push({d+1,r1,c1,r1+1,c1,1});
                    }
                }
            }
            if(dir==1){
              if(c1+1<n&&grid[r1][c1+1]==0&&c2+1<n&&grid[r2][c2+1]==0){
                 if(vis[r1][c1][0]==0){
                 vis[r1][c1][0]=1;
                 q.push({d+1,r1,c1,r1,c1+1,0});
                 }
              }
        }
        }
        return -1;
    }
};