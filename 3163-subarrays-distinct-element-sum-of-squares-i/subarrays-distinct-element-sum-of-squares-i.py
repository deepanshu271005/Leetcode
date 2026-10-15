class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans=0
        n=len(nums)
        for i in range(n):
            for j in range(n):
                distint=set()
                for k in range(i,j+1):
                  distint.add(nums[k])
                ans+=len(distint)*len(distint)                  
        return ans                
                                    