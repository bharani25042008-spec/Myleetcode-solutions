class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        //2+2-2^2=1
        //14-2+1^12=
        queue<pair<int,int>>q;
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[start]=1;
        q.push({0,start});
        while(!q.empty()){
              auto[d,node]=q.front();
              q.pop();
              if(node==goal) return d;
              if(node>=0&&node<=1000){
                  for(int i=0;i<n;i++){
                      int a=node+nums[i];
                      int b=node-nums[i];
                      int c=node^nums[i];
                      if(a==goal) return d+1;
                      if(a>=0&&a<=1000&&mp[a]==0){
                       mp[a]=1;
                      q.push({d+1,a});
                      }
                      if(b==goal) return d+1;
                      if(b>=0&&b<=1000&&mp[b]==0){
                      mp[b]=1;
                      q.push({d+1,b});
                      }
                      if(c==goal) return d+1;
                      if(c>=0&&c<=1000&&mp[c]==0){
                      mp[c]=1;
                      q.push({d+1,c});
                      }
                  }
              }
        }
        return -1;
    }
};