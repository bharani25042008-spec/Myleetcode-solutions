class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long s1=0;
        long long s2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            s1+=nums[i];
        }
        for(int i=n/2;i<n;i++){
            s2+=nums[i];
        }
        return s2-s1;
    }
};