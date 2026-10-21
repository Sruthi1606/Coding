class Solution{
public:
    int minOperations(string s){
        int n=s.length(),c=1;
        for(int i=1;i<n;i++){
            if(s[i]<s[i-1])c=0;
        }
        if(c)return 0;
        char minch='z',maxch='a';
        int minc=0,maxc=0;
        for(int i=0;i<n;i++){
            if(s[i]<minch){
                minch=s[i];
                minc=0;
            }
            if(s[i]>maxch){
                maxch=s[i];
                maxc=0;
            }
            if(s[i]==minch)minc++;
            if(s[i]==maxch)maxc++;
        }
        if(n==2)return -1;
        if(s[0]==minch||s[n-1]==maxch)return 1;
        if(s[0]==maxch&&maxc==1&&s[n-1]==minch&&minc==1)return 3;
        return 2;
    }
};