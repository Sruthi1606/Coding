class Solution{
public:
    int countIslands(vector<vector<int>>&grid,int k){
        int m=grid.size(),n=grid[0].size(),ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    long long sum=0;
                    dfs(grid,i,j,sum);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>&g,int i,int j,long long&sum){
        int m=g.size(),n=g[0].size();
        if(i<0||j<0||i>=m||j>=n||g[i][j]<=0) return;
        sum+=g[i][j];
        g[i][j]=0;
        dfs(g,i+1,j,sum);
        dfs(g,i-1,j,sum);
        dfs(g,i,j+1,sum);
        dfs(g,i,j-1,sum);
    }
};