class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
           priority_queue<tuple<int,int,int,int,int>,vector<tuple<int,int,int,int,int>>,greater<tuple<int,int,int,int,int>>>q;
    int m=grid.size();
    int n=grid[0].size();
        vector<vector<vector<vector<int>>>>dist(m,vector<vector<vector<int>>>(n,vector<vector<int>>(5,vector<int>(k+1,INT_MAX))));
        dist[0][0][4][k]=grid[0][0];
        dist[0][0][2][k]=grid[0][0];
        q.push({grid[0][0],0,0,4,k});
        q.push({grid[0][0],0,0,2,k});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
              auto[d,r,c,turn,rem]=q.top();
            q.pop();
            if(r==m-1&&c==n-1){
                 return d;
            }
            for(int i=0;i<4;i++){
                 int nr=r+dr[i];
                int nc=c+dc[i];
                int newturn=turn;
                if(nr>=m||nc>=n||nr<0||nc<0) continue;
                int newrem=rem;
                if(turn==1){
                     if(dr[i]==0&&dc[i]==-1){
                          newrem--;
                          newturn=3;//up to l
                     }
                }
                if(turn==1){
                      if(dr[i]==1&&dc[i]==0){
                           newrem--;
                           newturn=2;//up to d
                      }
                }
                if(turn==1){
                     if(dr[i]==0&&dc[i]==1){
                          newrem--;
                         newturn=4;//up to r
                     }
                }
                if(turn==2){
                     if(dr[i]==-1&&dc[i]==0){
                          newrem--;
                         newturn=1;//d to up
                     }
                }
                if(turn==2){
                     if(dr[i]==0&&dc[i]==-1){
                          newrem--;
                         newturn=3;//d to l
                     }
                } 
                if(turn==2){
                     if(dr[i]==0&&dc[i]==1){
                          newrem--;
                         newturn=4;//d to r
                     }
                }
                if(turn==3){
                     if(dr[i]==-1&&dc[i]==0){
                          newrem--;
                         newturn=1;//l to u
                     }
                }
                if(turn==3){
                     if(dr[i]==1&&dc[i]==0){
                          newrem--;
                         newturn=2;// l to d
                     }
                }
                if(turn==3){
                     if(dr[i]==0&&dc[i]==1){
                          newrem--;
                         newturn=4;//d to up
                     }
                }
                if(turn==4){
                     if(dr[i]==-1&&dc[i]==0){
                          newrem--;
                         newturn=1;
                     }
                }
                if(turn==4){
                     if(dr[i]==1&&dc[i]==0){
                          newrem--;
                         newturn=2;
                     }
                }
                if(turn==4){
                     if(dr[i]==0&&dc[i]==-1){
                          newrem--;
                         newturn=3;
                     }
                }
                
                if(newrem<0) continue;
                 int nd=grid[nr][nc]+d;
                 if(nd<dist[nr][nc][newturn][newrem]){
                      dist[nr][nc][newturn][newrem]=nd;
                     q.push({nd,nr,nc,newturn,newrem});
                 }     
            }
        }
        return -1;
    }
};