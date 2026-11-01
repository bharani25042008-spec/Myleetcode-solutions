class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int sum=0;
        sort(nums.begin(),nums.end());
        int min =nums[0];
        for(auto it:nums)
        {
            sum+=(it-min);
        }
        return sum;
    }
};