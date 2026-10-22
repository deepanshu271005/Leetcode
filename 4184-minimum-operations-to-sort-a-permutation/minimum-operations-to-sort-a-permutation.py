class Solution:
    def minOperations(self, nums):
        n = len(nums)
        idx = nums.index(0)
        
        is_inc = True
        for i in range(n):
            if nums[(idx + i) % n] != i:
                is_inc = False
                break
                
        is_dec = True
        for i in range(n):
            if nums[(idx - i + n) % n] != i:
                is_dec = False
                break
                
        ans = float('inf')
        
        # Case 1: The array is a rotation of the sorted array
        if is_inc:
            # Option A: Just rotate left `idx` times
            # Option B: Reverse, rotate the other way, reverse back
            ans = min(ans, idx, 2 + (n - idx) % n if idx > 0 else 0)
            
        # Case 2: The array is a rotation of the reversed sorted array
        if is_dec:
            # Option A: Reverse first, then rotate left to fix the 0
            # Option B: Rotate left to put 0 at the end, then reverse
            ans = min(ans, 1 + (n - 1 - idx) % n, 1 + (idx + 1) % n)
            
        return ans if ans != float('inf') else -1