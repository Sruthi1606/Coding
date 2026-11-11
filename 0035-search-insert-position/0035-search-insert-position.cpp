class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int idx=0;
        while(idx<n&&nums[idx]<target) idx++;
        return idx;

    }
};