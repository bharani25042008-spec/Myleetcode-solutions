class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
          vector<int>t;
          for(auto it:nums){
              if(it>=0){
                  t.push_back(it);
              }
          }
          int n=t.size();
          if(!t.empty()){
              k=k%n;
              rotate(t.begin(),t.begin()+k,t.end());
          }
          int id=0;
          for(int i=0;i<nums.size();i++){
              if(nums[i]>=0){
                  nums[i]=t[id++];
              }
          }
          return nums;
    }
};