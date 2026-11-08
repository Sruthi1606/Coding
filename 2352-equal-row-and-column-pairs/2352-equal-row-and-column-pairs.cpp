class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;      
        vector<int>rows(n),cols(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int f=1;
                for(int k=0;k<n;k++){
                    if(grid[i][k]!=grid[k][j]){
                        f=0;
                        break;
                    }
                }
                if(f) ans++;
            }
        } 
        return ans;
    }
};