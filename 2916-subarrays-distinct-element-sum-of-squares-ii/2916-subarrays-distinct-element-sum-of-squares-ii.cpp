class Solution{
public:
    int sumCounts(vector<int>& nums){
        const int mod=1e9+7;
        int n=nums.size();
        vector<long long>s(4*n),q(4*n),lazy(4*n);
        vector<int>last(100001,-1);
        long long ans=0;
        function<void(int,int,int,int,int)> upd=[&](int v,int l,int r,int a,int b){
            if(a>r||b<l)return;
            if(a<=l&&r<=b){
                q[v]=(q[v]+2*s[v]+r-l+1)%mod;
                s[v]=(s[v]+r-l+1)%mod;
                lazy[v]++;
                return;
            }
            int m=(l+r)/2;
            if(lazy[v]){
                long long x=lazy[v];
                q[v*2]=(q[v*2]+2*x*s[v*2]+x*x*(m-l+1))%mod;
                s[v*2]=(s[v*2]+x*(m-l+1))%mod;
                lazy[v*2]+=x;
                q[v*2+1]=(q[v*2+1]+2*x*s[v*2+1]+x*x*(r-m))%mod;
                s[v*2+1]=(s[v*2+1]+x*(r-m))%mod;
                lazy[v*2+1]+=x;
                lazy[v]=0;
            }
            upd(v*2,l,m,a,b);
            upd(v*2+1,m+1,r,a,b);
            s[v]=(s[v*2]+s[v*2+1])%mod;
            q[v]=(q[v*2]+q[v*2+1])%mod;
        };
        for(int i=0;i<n;i++){
            upd(1,0,n-1,last[nums[i]]+1,i);
            last[nums[i]]=i;
            ans=(ans+q[1])%mod;
        }
        return ans;
    }
};