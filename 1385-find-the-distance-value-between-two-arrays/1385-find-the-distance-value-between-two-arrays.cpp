class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c=0;
        for(auto&x:arr1){
            bool f=1;
            for(auto&y:arr2){
                f&=(abs(x-y)>d);
            }
            c+=f;
        }
        return c;
    }
};