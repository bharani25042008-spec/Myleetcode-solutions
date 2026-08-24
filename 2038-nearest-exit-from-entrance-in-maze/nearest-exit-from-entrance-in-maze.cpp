class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<tuple<int,int,int>>q;
        q.push({entrance[0],entrance[1],1});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
              auto [r,c,dist]=q.front();
              q.pop();
              for(int k=0;k<4;k++){
                 int nr=r+dr[k];
                 int nc=c+dc[k];
                 if(nr>=maze.size()||nc>=maze[0].size()||nr<0||nc<0){
                     continue;
                 }
                 if(vis[nr][nc]==1){
                    continue;
                 }
                 if(maze[nr][nc]=='+'){
                    continue;
                 }
                 if(nr==0||nc==0||nr==maze.size()-1||nc==maze[0].size()-1){
                     return dist;
                 }
                 vis[nr][nc]=1;
                 q.push({nr,nc,dist+1});

              }
        }
        return -1;
    }
};