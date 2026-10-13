from heapq import heappush,heappop 
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        ans=0
        pq=[]
        n=len(nums)
        for i in nums:
            heappush(pq,i*i)
        half=n//2   
        while half:
            half-=1
            ans-=pq[0]
            heappop(pq)
        while len(pq):
            ans+=pq[0]
            heappop(pq)
        return ans                           