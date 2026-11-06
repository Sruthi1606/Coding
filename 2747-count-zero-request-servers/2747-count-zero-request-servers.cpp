class Solution{
public:
    vector<int> countServers(int n,vector<vector<int>>& logs,int x,vector<int>& queries){
        int m=queries.size();
        vector<pair<int,int>> q;
        for(int i=0;i<m;i++)
            q.push_back({queries[i],i});
        sort(q.begin(),q.end());
        sort(logs.begin(),logs.end(),[](auto&a,auto&b){
            return a[1]<b[1];
        });
        vector<int> ans(m),cnt(n+1);
        int l=0,r=0,active=0;
        for(auto [t,id]:q){
            while(r<logs.size()&&logs[r][1]<=t){
                if(cnt[logs[r][0]]++==0)
                    active++;
                r++;
            }
            while(l<r&&logs[l][1]<t-x){
                if(--cnt[logs[l][0]]==0)
                    active--;
                l++;
            }
            ans[id]=n-active;
        }
        return ans;
    }
};