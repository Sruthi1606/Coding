
class Solution:
    def minOperations(self,nums:list[int])->int:
        n=len(nums)
        if n==1:
            return 0
        st=nums.index(0)
        asc=True
        dsc=True
        for i in range(1,n):
            value=nums[(st+i)%n]
            if value!=i:
                asc=False
            if value!=n-i:
                dsc=False
            if not asc and not dsc:
                return -1
        if asc:
            return min(st,n-st+2)
        return min(n-st,st+2)