class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
            set<int>st;
            st.insert(nums[0]);
            int n=nums.size();
            vector<int>pref(n);
            pref[0]=st.size();
            for(int i=1;i<n;i++){
                  st.insert(nums[i]);
                  pref[i]=st.size();
            }
            vector<int>suff(n);
            st.clear();
            st.insert(nums[n-1]);
            suff[n-1]=st.size();
            for(int i=n-2;i>=0;i--){
                 st.insert(nums[i]);
                 suff[i]=st.size();
            }
            vector<int>ans(n);
            for(int i=0;i<n;i++){
                int val1=pref[i];
                int val2=0;
                if(i!=n-1){
                     val2=suff[i+1];
                }
                ans[i]=val1-val2;
            }
            for(auto it:ans) cout<<it<<' ';
            return ans;
    }
};