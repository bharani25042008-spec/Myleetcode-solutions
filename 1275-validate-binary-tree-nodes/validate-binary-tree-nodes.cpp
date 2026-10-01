class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftchild, vector<int>& rightchild) {
           map<int,vector<int>>mp;
           for(int i=0;i<leftchild.size();i++){
                  if(leftchild[i]!=-1){
                       mp[leftchild[i]].push_back({i});
                  }
           }
           for(int i=0;i<rightchild.size();i++){
               if(rightchild[i]!=-1){
                    mp[rightchild[i]].push_back({i});
               }
           }
           int root=-1;
           for(int i=0;i<n;i++){
               if(mp[i].size()>1) return false;

           }
           int c=0;
           for(int i=0;i<n;i++){
                if(mp[i].size()==0){
                    c++;
                       root=i;
                }
           }
           if(c>1||c==0) return false;
           int cnt=0;
           vector<int>vis(n,0);
           queue<int>q;
           q.push(root);
           vis[root]=1;
           cnt++;
           while(!q.empty()){
                int s=q.size();
                for(int i=0;i<s;i++){
                    int node=q.front();
                    q.pop();
                    if(vis[node]==0){
                          vis[node]=1;
                          cnt++;
                    }
                    if(leftchild[node]!=-1){
                           q.push(leftchild[node]);
                    }
                    if(rightchild[node]!=-1){
                          q.push(rightchild[node]);
                    }
                }
           }
           return cnt==n;
    }
};