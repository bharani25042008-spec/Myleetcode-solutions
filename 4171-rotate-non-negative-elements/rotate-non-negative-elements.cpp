class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>temp;
        for(auto it:nums)
        {
              if(it>=0) temp.push_back(it);
        }
        if(!temp.empty()){
        int n=temp.size();
        k=k%n;
        std::rotate(temp.begin(),temp.begin()+k,temp.end());
        }
        int id=0;
        for(int i=0;i<nums.size();i++){
              if(nums[i]>=0){
                   nums[i]=temp[id++];
              }
        }
        return nums;
    }
};