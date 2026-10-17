class Solution {
public:
int func(int n){
       string s=to_string(n);
       int sum=0;
       for(auto it:s){
             sum+=it-'0';
       }
       return sum;
}
    int minSwaps(vector<int>& nums) {
           vector<pair<int,int>>p;
           for(auto it:nums){
                 int sum=func(it);
                 p.push_back({sum,it});
           }
           sort(p.begin(),p.end());
           map<int,int>mp;
           for(int i=0;i<nums.size();i++){
                 mp[p[i].second]=i;
           }
           int ans=0;
           int n=nums.size();
           vector<bool>vis(n,false);
           for(int i=0;i<n;i++){
               if(vis[i]) continue;
               int j=i;
               int c=0;
               while(!vis[j]){
                     vis[j]=true;
                     c++;
                     j=mp[nums[j]];
                    
               }
               ans+=c-1;
           }
           return ans;
    }
};