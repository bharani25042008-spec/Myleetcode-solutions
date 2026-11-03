class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
           long long ans=0;
           priority_queue<int>q;
           for(auto it:nums){
                 q.push(it);
           }
           while(!q.empty()&&k>0){
                long long val=q.top();
                q.pop();
                 if(mul>0){
                 ans+=val*mul;
                 mul--;
                 }else{
                     ans+=val;
                 }
                k--;
           }
        return ans;
           
    }
};