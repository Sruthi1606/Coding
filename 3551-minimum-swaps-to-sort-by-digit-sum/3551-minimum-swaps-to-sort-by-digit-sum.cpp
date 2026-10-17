class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> d(n),idx(n),pos(n),vis(n,0);
        for(int i=0;i<n;i++){
            int x=nums[i],s=0;
            while(x>0){
                s+=x%10;
                x/=10;
            }
            d[i]=s;
            idx[i]=i;
        }
        sort(idx.begin(),idx.end(),[&](int a,int b){
            if(d[a]!=d[b]) return d[a]<d[b];
            return nums[a]<nums[b];
        });
        for(int i=0;i<n;i++)
            pos[idx[i]]=i;
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                int j=i;
                while(!vis[j]){
                    vis[j]=1;
                    j=pos[j];
                }
            }
        }
        return n-c;
    }
};