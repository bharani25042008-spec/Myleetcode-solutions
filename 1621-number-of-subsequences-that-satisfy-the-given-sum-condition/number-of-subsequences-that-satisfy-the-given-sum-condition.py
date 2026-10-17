class Solution:
    def numSubseq(self, nums: list[int], target: int) -> int:
        i=0
        j=len(nums)-1
        ans=0
        nums.sort()
        while i<=j:
            sum=nums[i]+nums[j]
            if sum<=target:
                ans=(ans+pow(2,j-i,10**9+7))%(10**9+7)
                i+=1
            elif sum>target:
                j-=1
        return ans

