class Solution:
    def f(self,k:int,piles:list[int])->int:
        cnt=0
        for i in piles:
            cnt=cnt+math.ceil(i/k)
        return cnt    

    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        l=1 
        r=10**9
        ans=10**9
        while l<=r:
            mid=(l+r)//2
            if self.f(mid,piles)<=h:
                r=mid-1
                ans=mid
            else :
                l=mid+1
        return ans

