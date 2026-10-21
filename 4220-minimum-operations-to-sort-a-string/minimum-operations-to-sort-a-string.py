class Solution:
    def minOperations(self, s: str) -> int:
        first='z'
        last='a'
        n=len(s)
        for i in s:
            if i<first:
                first=i
            if i>last:
                last=i
        if s==''.join(sorted(s)):
            return 0
        if n==2:
            return -1     
        if (s[0] == first and s[n-1] == last) or (s[0] == first) or (s[n-1] == last):
            return 1
        if(s[0]==last and s[n-1]==first and s.count(first)==1 and s.count(last)==1):
            return 3
        return 2


