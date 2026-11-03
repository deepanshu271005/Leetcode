class Solution:
    def minMoves(self, nums: List[int]) -> int:
        ans=0
        maxi=0
        for i in nums:
            maxi=max(maxi,i)
        for i in nums:
            ans+=abs(maxi-i)
        return ans                
