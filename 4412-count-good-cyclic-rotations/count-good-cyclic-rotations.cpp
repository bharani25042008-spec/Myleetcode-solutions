class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        const int mod=1e9;
        vector<long long>ans(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
             ans.push_back(nums[i]);
        }
        vector<long long>pref(2*n);
        pref[0]=ans[0];
        for(int i=1;i<2*n;i++){
             pref[i]=(pref[i-1]+(long long)ans[i]);
        }
        int res=0;
        long long tot=accumulate(nums.begin(),nums.end(),0LL);
        for(int i=0;i<n;i++){
             long long s1=0;
             long long s2=0;
             if(i==0){
                 s1=pref[i+((n/2)-1)];
                 s2=tot-s1;
                 if(s1>s2) res++;
             }else{

             s1=pref[i+((n/2)-1)]-pref[i-1];
             s2=tot-s1;
             if(s1>s2) res++;
             }
        }
        return res;
    }
};