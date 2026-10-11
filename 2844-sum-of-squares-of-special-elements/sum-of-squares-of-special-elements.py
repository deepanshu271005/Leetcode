class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        ans=0
        n=len(nums)
        for i in range(n+1):
            if i==0:
               continue
            if  n%i==0:
                ans+=nums[i-1]*nums[i-1]       
        return ans