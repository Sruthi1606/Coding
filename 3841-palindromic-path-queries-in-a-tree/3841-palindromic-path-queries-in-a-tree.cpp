class BIT{
    vector<int> t;
    int n;
public:
    BIT(int n):n(n),t(n+1,0){}
    int lowbit(int x){return x&-x;}
    void update(int x,int v){
        while(x<=n){
            t[x]^=v;
            x+=lowbit(x);
        }
    }
    int query(int x){
        int a=0;
        while(x){
            a^=t[x];
            x-=lowbit(x);
        }
        return a;
    }
    void updateRange(int l,int r,int v){
        update(l,v);
        update(r+1,v);
    }
};

class Solution{
public:
    vector<bool> palindromePath(int n,vector<vector<int>>& edges,string s,vector<string>& queries){
        vector<vector<int>> g(n);
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int LOG=32-__builtin_clz(n),t=0;
        vector<vector<int>> fa(n,vector<int>(LOG));
        vector<int> dep(n),l(n),r(n);
        auto dfs=[&](auto&& dfs,int u,int p)->void{
            l[u]=++t;
            fa[u][0]=p;
            for(int v:g[u]) if(v!=p){
                dep[v]=dep[u]+1;
                dfs(dfs,v,u);
            }
            r[u]=t;
        };
        dfs(dfs,0,0);
        for(int j=1;j<LOG;j++)
            for(int i=0;i<n;i++)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        auto lca=[&](int u,int v){
            if(dep[u]<dep[v]) swap(u,v);
            int d=dep[u]-dep[v];
            for(int i=0;i<LOG;i++) if(d>>i&1) u=fa[u][i];
            if(u==v) return u;
            for(int i=LOG-1;i>=0;i--)
                if(fa[u][i]!=fa[v][i]){
                    u=fa[u][i]; v=fa[v][i];
                }
            return fa[u][0];
        };
        BIT bit(n+1);
        for(int i=0;i<n;i++) bit.updateRange(l[i],r[i],1<<(s[i]-'a'));
        vector<bool> ans;
        for(string q:queries){
            stringstream ss(q);
            string op; ss>>op;
            if(op=="update"){
                int u; char c; ss>>u>>c;
                bit.updateRange(l[u],r[u],(1<<(s[u]-'a'))^(1<<(c-'a')));
                s[u]=c;
            }else{
                int u,v; ss>>u>>v;
                int w=lca(u,v);
                int m=bit.query(l[u])^bit.query(l[v])^(1<<(s[w]-'a'));
                ans.push_back(__builtin_popcount(m)<=1);
            }
        }
        return ans;
    }
};