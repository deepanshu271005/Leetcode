class Solution:
    def minInsertions(self, s: str) -> int:
        open=0
        ans=0
        n=len(s)
        i=0
        while i<n:
            if s[i]=='(':
                open=open+1 
            else :
                if i+1<n and s[i+1]==')':
                    i=i+1
                else :
                    ans=ans+1
                open=open-1
            if open<0:
                ans=ans+1
                open=0                
            i+=1        

        return ans+2*open;                                        