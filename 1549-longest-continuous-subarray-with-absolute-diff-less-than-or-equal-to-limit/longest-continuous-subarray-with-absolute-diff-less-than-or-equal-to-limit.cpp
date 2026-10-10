class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
         multiset<int>st;
         int l=0;
         int maxi=0;
         for(int i=0;i<nums.size();i++){
                st.insert(nums[i]);
                while(abs(*st.begin()-*st.rbegin())>limit){
                        auto it=st.find(nums[l]);
                        if(it!=st.end()){
                               st.erase(it);
                        }
                        l++;
                }
                maxi=max(maxi,i-l+1);
         }
         return maxi;
    }
};