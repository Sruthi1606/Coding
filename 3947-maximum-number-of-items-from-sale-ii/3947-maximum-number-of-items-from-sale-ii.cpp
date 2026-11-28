class Solution{
public:
	int maximumSaleItems(vector<vector<int>>&items,int budget){
		int n=items.size();
		vector<int>cnt(n+1,0),mult(n+1,0);
		for(int i=0;i<n;i++){
			cnt[items[i][0]]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j+=i){
				mult[i]+=cnt[j];
			}
		}
		int mn=INT_MAX;
		vector<pair<int,int>>v;
		for(int i=0;i<n;i++){
			int f=items[i][0],p=items[i][1];
			mn=min(mn,p);
			int g=mult[f]-1;
			if(g>0){
				v.push_back({p,g});
			}
		}
		sort(v.begin(),v.end());
		long long spent=0,total=0;
		for(int i=0;i<v.size();i++){
			int p=v[i].first;
			int g=v[i].second;
			if(p>2LL*mn)break;
			long long can=min((long long)g,(budget-spent)/p);
			total+=can*2;
			spent+=can*p;
		}
		total+=(budget-spent)/mn;
		return total;
	}
};