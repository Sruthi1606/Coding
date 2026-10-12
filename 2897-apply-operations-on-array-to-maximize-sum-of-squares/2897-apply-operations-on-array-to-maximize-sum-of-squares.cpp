class Solution {
public:
    int maxSum(vector<int>& nums,int k) {
        const int MOD=1e9+7;
        vector<int>c(30,0);
        for(int n:nums){
            for(int i=0;i<30;i++){
                if(n&(1<<i)){
                    c[i]++;
                }
            }
        }
        long long r=0;
        for(int i=0;i<k;i++){
            long long cur=0;
            for(int j=29;j>=0;j--){
                if(c[j]>0){
                    cur|=(1LL<<j);
                    c[j]--;
                }
            }
            r=(r+cur*cur)%MOD;
        }
        return r;
    }
};