class Solution {
public:
int func(vector<int>&v,vector<vector<int>>&intervals,map<vector<int>,int>&mp){
       int ans=INT_MAX;
       int l=0;
       int r=intervals.size()-1;
       int val=v[1];
       while(l<=r){
           int mid=(l+r)/2;
           if(intervals[mid][0]>=val){
                ans=min(ans,mp[intervals[mid]]);
                r=mid-1;
           }else{
                l=mid+1;
           }
       }
       if(ans==INT_MAX) return -1;
       return ans;
}
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
         int n=intervals.size();
         vector<int>ans(n);
         map<vector<int>,int>mp;
         for(int i=0;i<intervals.size();i++){
               mp[intervals[i]]=i;
         }
         vector<vector<int>>temp=intervals;
         sort(intervals.begin(),intervals.end());
         for(int i=0;i<n;i++){
              int val=func(temp[i],intervals,mp);
              ans[i]=val;
         }
         return ans;
    }
};