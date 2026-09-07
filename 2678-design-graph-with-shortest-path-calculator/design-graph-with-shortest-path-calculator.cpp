class Graph {
public:
vector<vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
         adj.resize(n);
          //vector<vector<pair<int,int>>>adj(n);
          //this->adj=adj;
          for(auto it:edges){
               adj[it[0]].push_back({it[1],it[2]});
          }
    }
    
    void addEdge(vector<int> edge) {
           adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
           int n=adj.size();
           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
           q.push({0,node1});
           vector<int>dist(n,INT_MAX);
           dist[node1]=0;
           while(!q.empty()){
               auto[d,node]=q.top();
               q.pop();
               if(node==node2){
                    return d;
               }
               for(auto nei:adj[node]){
                     int nd=d+nei.second;
                     if(nd<dist[nei.first]){
                         dist[nei.first]=nd;
                         q.push({nd,nei.first});
                     }
               }
           }
           return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */