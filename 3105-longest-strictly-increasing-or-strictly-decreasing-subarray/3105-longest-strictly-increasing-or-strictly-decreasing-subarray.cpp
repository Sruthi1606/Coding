class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            int currlen=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[j-1]) currlen++;
                else break;
            }
            maxlen=max(maxlen,currlen);
        }
        for(int i=0;i<n;i++){
            int currlen=1;
            for(int k=i+1;k<n;k++){
                if(nums[k]<nums[k-1]) currlen++;
                else break;
            }
            maxlen=max(maxlen,currlen);
        }
        return maxlen;
    }
};