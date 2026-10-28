class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>dp(n,vector<bool>(1024,false));
        dp[0][grid[0][0]]=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                vector<bool>next(1024,false);
                for(int k=0;k<1024;k++){
                    if(dp[j][k]) next[k^grid[i][j]]=true;
                    if(j>0&&dp[j-1][k]) next[k^grid[i][j]]=true;
                }
                dp[j]=next;
            }
        }
        for(int k=0;k<1024;k++)
            if(dp[n-1][k]) return k;
        return -1;
    }
};