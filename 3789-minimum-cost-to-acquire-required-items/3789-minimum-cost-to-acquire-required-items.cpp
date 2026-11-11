class Solution{
public:
    long long minimumCost(int cost1,int cost2,int costBoth,int need1,int need2){
        long long tc=0;
        if(cost1+cost2<=costBoth) tc=1LL*cost1*need1+1LL*cost2*need2;
        else{
            int c3=min(need1,need2);
            tc=1LL*c3*costBoth;
            need1-=c3;
            need2-=c3;
            if(need1>0) tc+=1LL*need1*min(cost1,costBoth);
            else if(need2>0) tc+=1LL*need2*min(cost2,costBoth);
        }
        return tc;
    }
};