class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(i==j){
                  ans+=nums[i];
                  i++;
                  j--;
            }else{
              string s1=to_string(nums[i]);
              string s2=to_string(nums[j]);
              long long sum1=stoll(s1+s2);
              ans+=sum1;
              i++;
              j--;
        }
        }
        return ans;
    }
};