class Solution{
public:
    vector<int> assignTasks(vector<int>& servers,vector<int>& tasks){
        int m=servers.size(),n=tasks.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>busy;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>idle;
        for(int i=0;i<m;i++)
            idle.push({servers[i],i});
        vector<int> ans;
        long long t=0;
        for(int i=0;i<n;i++){
            t=max(t,(long long)i);
            while(!busy.empty()&&busy.top().first<=t){
                int idx=busy.top().second;
                busy.pop();
                idle.push({servers[idx],idx});
            }
            if(idle.empty()){
                t=busy.top().first;
                while(!busy.empty()&&busy.top().first<=t){
                    int idx=busy.top().second;
                    busy.pop();
                    idle.push({servers[idx],idx});
                }
            }
            int idx=idle.top().second;
            idle.pop();
            ans.push_back(idx);
            busy.push({t+tasks[i],idx});
        }
        return ans;
    }
};