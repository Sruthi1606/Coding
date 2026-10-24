
class Solution{
public:
    int countDaysTogether(string arriveAlice,string leaveAlice,string arriveBob,string leaveBob){
        int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int a=0,b=0,c=0,d=0;
        for(int i=1;i<stoi(arriveAlice.substr(0,2));i++) a+=days[i];
        a+=stoi(arriveAlice.substr(3,2));
        for(int i=1;i<stoi(leaveAlice.substr(0,2));i++) b+=days[i];
        b+=stoi(leaveAlice.substr(3,2));
        for(int i=1;i<stoi(arriveBob.substr(0,2));i++) c+=days[i];
        c+=stoi(arriveBob.substr(3,2));
        for(int i=1;i<stoi(leaveBob.substr(0,2));i++) d+=days[i];
        d+=stoi(leaveBob.substr(3,2));
        int start=max(a,c);
        int end=min(b,d);
        if(start>end) return 0;
        return end-start+1;
    }
};
