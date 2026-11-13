class Solution{
public:
    long long countNonDecreasingSubarrays(vector<int>&nums,int k){
        int n=nums.size();
        long long ans=0,op=0;
        priority_queue<pair<int,int>>q;
        vector<vector<int>>cnt(n);
        vector<int>pos(n,n);
        stack<int>st;
        for(int l=0,r=0;r<n;r++){
            while(!st.empty()&&nums[r]>=nums[st.top()]){
                pos[st.top()]=r;
                st.pop();
            }
            if(!st.empty()) cnt[st.top()].push_back(r);
            st.push(r);
            q.emplace(nums[r],r);
            op+=max(0,q.top().first-nums[r]);
            while(op>k){
                for(int i:cnt[l]) op-=(long long)(nums[l]-nums[i])*(min(pos[i],r+1)-i);
                l++;
            }
            while(!q.empty()&&q.top().second<l) q.pop();
            ans+=r-l+1;
        }
        return ans;
    }
};