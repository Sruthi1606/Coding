class Solution {
public:
    bool canAliceWin(int n) {
        int a=10,k=0;
        while(n>=a) {
            n-=a;
            a--;
            k++;
        }
        return k%2==1;
    }
};