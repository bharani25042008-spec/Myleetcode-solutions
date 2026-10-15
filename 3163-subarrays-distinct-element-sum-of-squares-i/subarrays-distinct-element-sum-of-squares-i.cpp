class Solution {
public:
int func(vector<int>res){
       set<int>st(res.begin(),res.end());
       return st.size()*st.size();
}
    int sumCounts(vector<int>& nums) {
           int ans=0;
           for(int i=0;i<nums.size();i++){
                 vector<int>res;
                 for(int j=i;j<nums.size();j++){
                        res.push_back(nums[j]);
                        ans+=func(res);
                 }
           }
           return ans;
    }
};