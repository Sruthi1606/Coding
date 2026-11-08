class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>row(n),cols(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]+=mat[i][j];
                cols[j]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]&&row[i]+cols[j]==2) ans++;
            }
        }
        return ans;
        
    }
};