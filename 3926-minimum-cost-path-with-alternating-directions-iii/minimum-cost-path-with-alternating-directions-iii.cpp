class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<long long>>>dist(m,vector<vector<long long>>(n,vector<long long>(2,LLONG_MAX)));
        dist[0][0][0]=1;
        priority_queue<tuple<long long,int,int,int>,vector<tuple<long long,int,int,int>>,greater<tuple<long long,int,int,int>>>q;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        q.push({1,0,0,0});
        while(!q.empty()){
              auto[d,r,c,p]=q.top();
              q.pop();
              if(r==m-1&&c==n-1){
                 return d;
              }
            int np = (p + 1) % 2;
            long long waitCost = d + penalty[r][c];
            if (waitCost < dist[r][c][np]) {
                dist[r][c][np] = waitCost;
                q.push({
                    waitCost,
                    r,
                    c,
                    np
                });
            }
              for(int i=0;i<4;i++){
                 int nr=r+dr[i];
                 int nc=c+dc[i];
                 long long cost=(nr+1)*(nc+1);
                 if(nr>=m||nc>=n||nr<0||nc<0) continue;
                 if((p+1)%2==1){
                    if(dr[i]==0&&dc[i]==-1){
                        cost+=penalty[r][c];
                    }
                    if(dr[i]==-1&&dc[i]==0){
                       cost+=penalty[r][c];
                 }
                 }else{
                   if(dr[i]==0&&dc[i]==1){
                    cost+=penalty[r][c];
                 }
                   if(dr[i]==1&&dc[i]==0){
                     cost+=penalty[r][c];
                   }
               }
               if(cost+d<dist[nr][nc][(p+1)%2]){
                 dist[nr][nc][(p+1)%2]=cost+d;
                 q.push({cost+d,nr,nc,(p+1)%2});
               }
        }
    }
    return 0;
    }
};
//wait cost  mattum ennala kandu pudika mudila just wait cost na same cell laiyae nikkanum but how that cost induces the shortest distance it is the major question?--ok okay qns laiyae koduthutaanunga