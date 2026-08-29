class Solution {
public:
int func(int n,vector<vector<int>>&adj){
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
       q.push({0,0});
       vector<int>dist(n,INT_MAX);
       dist[0]=0;
       while(!q.empty()){
            auto[d,node]=q.top();
            q.pop();
            if(node==n-1){
                  return d;
            }
            for(auto nei:adj[node]){
                 if(d+1<dist[nei]){
                     dist[nei]=d+1;
                     q.push({dist[nei],nei});
                 }
            }
       }
       return 0;
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
             vector<vector<int>>adj(n);
             vector<int>ans;
             for(int i=0;i<n-1;i++){
                   adj[i].push_back(i+1);
             }
             for(int i=0;i<queries.size();i++)
             {
                  adj[queries[i][0]].push_back(queries[i][1]);
                  ans.push_back(func(n,adj));
             }
             return ans;
    }
};