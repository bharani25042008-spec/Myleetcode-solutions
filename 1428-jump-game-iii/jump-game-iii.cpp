class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
            int n=arr.size();
            vector<int>vis(n,0);
            vis[start]=1;
            queue<int>q;
            q.push(start);
            while(!q.empty()){
                  int node=q.front();
                  q.pop();
                  if(arr[node]==0){
                       return true;
                  }
                  int s1=node+arr[node];
                  int s2=node-arr[node];
                  if(s1<n&&vis[s1]==0){
                     vis[s1]=1;
                     q.push(s1);
                  }
                  if(s2>=0&&vis[s2]==0){
                     vis[s2]=1;
                     q.push(s2);
                  }
            }
            return false;
    }
};