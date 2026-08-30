class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end_node) {
          vector<vector<int>>adj(n);
          unordered_map<string,double>mp;
          for(int i=0;i<edges.size();i++){
              adj[edges[i][0]].push_back(edges[i][1]);
              mp[to_string(edges[i][0])+"->"+to_string(edges[i][1])]=succProb[i];
              adj[edges[i][1]].push_back(edges[i][0]);
              mp[to_string(edges[i][1])+"->"+to_string(edges[i][0])]=succProb[i];
          }
          priority_queue<tuple<double,int>>q;
          vector<double>dist(n,0.0);
          dist[start]=1.0;
          q.push({1.0,start});
          while(!q.empty()){
             auto [d,node]=q.top();
             q.pop();
             if(node==end_node){
                 return d;
          }
          for(auto nei:adj[node]){
              double nd=d*mp[to_string(node)+"->"+to_string(nei)];
              if(nd>dist[nei]){
               dist[nei]=nd;
               q.push({nd,nei});
          }
    }
          }
    return 0;
    }
};