class Solution:
    def numOfWays(self,nums:List[int])->int:
        mod=10**9+7
        def dfs(nums):
            m=len(nums)
            if m<3:
                return 1
            ln=[a for a in nums if a<nums[0]]
            rn=[a for a in nums if a>nums[0]]
            return dfs(ln)*dfs(rn)*comb(m-1,len(ln))%mod
        return (dfs(nums)-1)%mod