class ProductOfNumbers{
	vector<int>v;
	int size=0;
public:
	ProductOfNumbers(){
		v.push_back(1);
	}
	void add(int num){
		if(num==0){
			v.clear();
			v.push_back(1);
			size=0;
		}
		else{
			v.push_back(v[size]*num);
			size++;
		}
	}
	int getProduct(int k){
		if(k>size)return 0;
		return v[size]/v[size-k];
	}
};