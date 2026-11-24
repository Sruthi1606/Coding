class Solution{
public:
	int maxLength(vector<int>&nums){
		int res=0;
		for(int i=0;i<nums.size();i++){
			long long p=nums[i];
			long long g=nums[i];
			long long l=nums[i];
			for(int j=i+1;j<nums.size();j++){
				p=p*nums[j];
				g=gcd(g,nums[j]);
				l=lcm(l,nums[j]);
				if(p>g*l)break;
				if(p==g*l){
					res=max(res,j-i+1);
				}
			}
		}
		return res;
	}
};