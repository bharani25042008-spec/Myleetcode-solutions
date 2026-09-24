// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid, int k) {
//           int m=grid.size();
//           int n=grid[0].size();
//           priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>q;
//           vector<vector<vector<int>>>dist(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
//           map<int,vector<pair<int,int>>>mp;
//    for(int i=0;i<m;i++){
//     for(int j=0;j<n;j++){
//         for(int r=0;r<m;r++){
//             for(int c=0;c<n;c++){

//                 if(grid[r][c] <= grid[i][j] &&
//                    !(r == i && c == j)) {

//                     mp[grid[i][j]].push_back({r,c});
//                 }
//             }
//         }
//     }
// }
//           dist[0][0][k]=0;
//           q.push({0,0,0,k});
//           while(!q.empty()){
//               auto[d,r,c,rem]=q.top();
//               q.pop();
//               if(d != dist[r][c][rem])
//                   continue;
//               if(r==m-1&&c==n-1){
//                   return d;
//               }
//               int nr=r;
//               int nc=c+1;
//               if(nr>=0&&nc>=0&&nr<m&&nc<n){
//                     int nd=d+grid[nr][nc];
//                     if(nd<dist[nr][nc][rem]){
//                          dist[nr][nc][rem]=nd;
//                          q.push({nd,nr,nc,rem});
//                     }
//               }
//               int n_r=r+1;
//               int n_c=c;
//                if(n_r>=0&&n_c>=0&&n_r<m&&n_c<n){
//                     int nd=d+grid[n_r][n_c];
//                     if(nd<dist[n_r][n_c][rem]){
//                          dist[n_r][n_c][rem]=nd;
//                          q.push({nd,n_r,n_c,rem});
//                     }
//               }
//               for(auto it:mp[grid[r][c]]){
//                     int newrem=rem-1;
//                    if(newrem<0) continue;
//                    int nd=d;
//                    if(nd<dist[it.first][it.second][newrem]){
//                       dist[it.first][it.second][newrem]=nd;
//                       q.push({nd,it.first,it.second,newrem});
//                    }
//               }

//           }
//     return 0;
//     }
// };
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
          int m=grid.size();
          int n=grid[0].size();
          priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>q;
          vector<vector<vector<int>>>dist(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
          vector<vector<pair<int,int>>> mp(10005);
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]].push_back({i,j}); 
            }
          }
          vector<int> max_val(k + 1, -1);
          
          dist[0][0][k]=0;
          q.push({0,0,0,k});
          
          while(!q.empty()){
              auto[d,r,c,rem]=q.top();
              q.pop();
              if(d > dist[r][c][rem]) continue;
              if(r==m-1&&c==n-1){
                  return d;
              }
              int nr=r;
              int nc=c+1;
              if(nr>=0&&nc>=0&&nr<m&&nc<n){
                    int nd=d+grid[nr][nc];
                    if(nd<dist[nr][nc][rem]){
                         dist[nr][nc][rem]=nd;
                         q.push({nd,nr,nc,rem});
                    }
              }
              int n_r=r+1;
              int n_c=c;
               if(n_r>=0&&n_c>=0&&n_r<m&&n_c<n){
                    int nd=d+grid[n_r][n_c];
                    if(nd<dist[n_r][n_c][rem]){
                         dist[n_r][n_c][rem]=nd;
                         q.push({nd,n_r,n_c,rem});
                    }
              }
              int newrem = rem - 1; 
              if(newrem >= 0 && grid[r][c] > max_val[rem]){
                  for(int v = max_val[rem] + 1; v <= grid[r][c]; v++){
                      for(auto it : mp[v]){
                           int nd = d;
                           if(nd < dist[it.first][it.second][newrem]){
                              dist[it.first][it.second][newrem] = nd;
                              q.push({nd, it.first, it.second, newrem});
                           }
                      }
                  }
                  max_val[rem] = grid[r][c];
              }
          }
    return 0;
    }
};