class Solution {
public:
//Even if i didn't have any experience in any particular stack i will learn them in a short period of time and ace it
bool func(int n,int mini,int maxi){
        return (n>=mini)&&(n<=maxi);
}
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        multiset<int>st;
        int l=0;

        for(int i=0;i<nums.size();i++){
           st.insert(nums[i]);
           while(!st.empty()&&(!func(*st.begin(),minK,maxK)||!func(*st.rbegin(),minK,maxK))){
                 auto it=st.find(nums[l]);
                 if(it!=st.end()){
                     st.erase(it);
                 }
                 l++;
           }
           ans+=(i-l+1);
        }
        return ans;
    }
};
