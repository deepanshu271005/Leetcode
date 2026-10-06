class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        cnt=0
        ans=0
        for i in s:
            if i=='(':
                cnt=cnt+1
            else : 
                cnt=cnt-1

            if cnt<0:
                ans=ans+abs(cnt)
                cnt=0
        return ans+cnt
