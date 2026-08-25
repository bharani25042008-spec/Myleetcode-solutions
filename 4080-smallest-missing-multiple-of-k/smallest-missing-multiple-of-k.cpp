class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=1;i<=500;i++){
             if(i%k==0){
                 ans.push_back(i);
             }
        }
        for(auto it:ans){
            if(st.find(it)==st.end()){
                 return it;
            }
        }
        return 0;
    }
};