class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
           vector<vector<pair<int,int>>>adj(n);
           for(int i=0;i<edges.size();i++){
             adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
             adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
           }
           priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
           q.push({passingFees[0],0,0});
           vector<vector<int>>dist(n,vector<int>(maxTime+1,INT_MAX));
           dist[0][0]=passingFees[0];
           while(!q.empty()){
             auto[cost,node,time]=q.top();
             q.pop();
             if(node==n-1){
                  return cost;
             }
             for(auto nei:adj[node]){
                   int nd=passingFees[nei.first]+cost;
                   int nt=time+nei.second;
                   if(nt<=maxTime&&nd<dist[nei.first][nt]){
                     dist[nei.first][nt]=nd;
                     q.push({nd,nei.first,nt});
                   }
             }
           }
           return -1;
    }
};