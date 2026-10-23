class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        dummy=sorted(nums)
        store=[]
        for i in range(len(nums)):
            if dummy[i]!=nums[i]:
                store.append(nums[i])
                
        #now from all the elemnt in the store i need to find out the max bits that are ON for ALL 
        ans=0
        bits=[0]*32
        for i in store:
            #extract the bits of this
            for bit in range(32):
                if ((1<<bit)&i):
                    bits[bit]+=1
        maxi=len(store)
        for i in range(len(bits)):
            if bits[i]==maxi and maxi!=0:
                #this bit it ON in all the store element 
                ans|=(1<<i)           
        return ans                                    
                                    
        