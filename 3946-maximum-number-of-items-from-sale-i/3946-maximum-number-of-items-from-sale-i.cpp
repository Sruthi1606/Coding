class Solution{
public:
	int maximumSaleItems(vector<vector<int>>&items,int budget){
		vector<int>f(budget+1,0);
        int n=items.size();
		int mn=INT_MAX;
		for(int i=0;i<n;i++){
			int factor=items[i][0];
			int price=items[i][1];
			mn=min(mn,price);
			int cnt=0;
			for(int j=0;j<n;j++){
				if(items[j][0]%factor==0){
					cnt++;
				}
			}
			for(int j=budget;j>=price;j--){
				f[j]=max(f[j],f[j-price]+cnt);
			}
		}
		int ans=0;
		for(int i=0;i<=budget;i++){
			ans=max(ans,f[i]+(budget-i)/mn);
		}
		return ans;
	}
};