class Solution{
public:
    int shortestPath(int n,vector<vector<int>>& edges,string labels,int k){
        vector<vector<pair<int,int>>> g(n);
        for(auto e:edges) g[e[0]].push_back({e[1],e[2]});
        vector<vector<long long>> dis(n,vector<long long>(k+1,LLONG_MAX));
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>> pq;
        dis[0][1]=0;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            long long d=a.first;
            int x=a.second.first,c=a.second.second;
            if(d!=dis[x][c]) continue;
            if(x==n-1) return d;
            for(auto e:g[x]){
                int y=e.first,w=e.second;
                int nc=labels[x]==labels[y]?c+1:1;
                if(nc<=k && d+w<dis[y][nc]){
                    dis[y][nc]=d+w;
                    pq.push({d+w,{y,nc}});
                }
            }
        }
        return -1;
    }
};