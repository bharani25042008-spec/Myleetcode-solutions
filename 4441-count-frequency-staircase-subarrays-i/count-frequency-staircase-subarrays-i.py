class Solution:
    def countStaircase(self, nums: list[int]) -> int:
        n=len(nums)
        total=0
        for i in range(n):
            set1=set()
            freq={}    
            for j in range(i,n):
                if nums[j] not in set1:
                    set1.add(nums[j])
                freq[nums[j]]=freq.get(nums[j], 0)+1
                valid=True
                curr=1
                for key,val in freq.items():
                    if curr!=val:
                        valid=False
                        break
                    else:
                        curr+=1            
                if valid==True:
                    total+=1

        return total
                    