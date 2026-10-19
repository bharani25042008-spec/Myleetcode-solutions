class Solution {
public:
int c2(vector<int>&nums,int target){
        int ans=-1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                  ans=mid;
                  l=mid+1;
            }else if(nums[mid]<target){
                  l=mid+1;
            }else if(nums[mid]>target){
                  r=mid-1;
            }
        }
        return ans;
}
int c1(vector<int>&nums,int target){
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r){
              int mid=(l+r)/2;
              if(nums[mid]==target){
                   ans=mid;
                   r=mid-1;
              }else if(nums[mid]<target){
                   l=mid+1;
              }else if(nums[mid]>target){
                   r=mid-1;
              }
        }
        return ans;
}
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int first=c1(nums,target);
        int last=c2(nums,target);
        if(first==-1&&last==-1) return ans;
        for(int i=first;i<=last;i++){
             if(nums[i]==target){
                   ans.push_back(i);
             }
        }
        return ans;
        
    }
};