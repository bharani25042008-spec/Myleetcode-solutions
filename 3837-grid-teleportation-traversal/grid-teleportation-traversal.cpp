class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        deque<tuple<int,int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        q.push_front({0,0,0});
        map<char,vector<pair<int,int>>>mp;
        for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[0].size();j++){
                 mp[matrix[i][j]].push_back({i,j});
             }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
             auto[d,r,c]=q.front();
             q.pop_front();
             if(r==m-1&&c==n-1){
                  return d;
             }
                 if(matrix[r][c]>='A'&&matrix[r][c]<='Z'){
                       for(auto it:mp[matrix[r][c]]){
                            //   if(vis[it.first][it.second]==1) continue;
                             if(d<dist[it.first][it.second]){
                              dist[it.first][it.second]=d;
                              q.push_front({d,it.first,it.second});              
                       }
                       }
                       mp.erase(matrix[r][c]);
                 }
                 for(int i=0;i<4;i++){
                 int nr=r+dr[i];
                 int nc=c+dc[i];
                 if(nr>=m||nc>=n||nr<0||nc<0) continue;
                 if(matrix[nr][nc]=='#') continue;
                       if(d+1<dist[nr][nc]){
                       dist[nr][nc]=d+1;
                       q.push_back({d+1,nr,nc});   
                       }             
             }
        }  
    return -1;
    }
};