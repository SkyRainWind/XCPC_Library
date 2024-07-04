// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
    {
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline ll read()
    {
        bool sign=0; char ch=nc();ll x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};
using namespace fastIO;
#define qr() read()

int n,m;
ll dp[maxn];
struct node{int to,e,p;};
struct edges{int x,y,e,p;};
vector<edges>ed;
vector<node>g0[maxn],g[maxn],h[maxn];
vector<ll>dis;

struct _scc{
    int dfn[maxn], low[maxn], dfs_clock;
    int stk[maxn], tp = 0, belong[maxn], tot=0, sz[maxn];
    _scc(){}
    
    void init(){
        dfs_clock = tp = tot = 0;
        for(int i=1;i<=n;i++)
            dfn[i] = low[i] = sz[i] = belong[i] = 0;
    }
    
    void tarjan(int x){
        dfn[x] = low[x] = ++ dfs_clock; 
        stk[++ tp] = x;
        for(auto now : g[x]){
            int u = now.to;
            if(!dfn[u]){
                tarjan(u);
                low[x] = min(low[x], low[u]);
            }else if(!belong[u])
                low[x] = min(low[x], dfn[u]); 
        }
        if(low[x] == dfn[x]){
            belong[x] = ++tot;
            ++sz[tot];
            while(stk[tp] != x){
                ++sz[tot];
                belong[stk[tp]] = tot;
                -- tp;
            }
            -- tp;
        }
    }
    
    void getscc(){
        for(int i=1;i<=n;i++)
            if(!dfn[i])tarjan(i);
    }
    
    void deal(){
        for(int i=0;i<ed.size();i++){
            int x = ed[i].x, y = ed[i].y;
            if(belong[x] != belong[y]){
                h[belong[x]].push_back(node{belong[y], ed[i].e, ed[i].p});
            }
        }
    }
};
struct _scc scc;

void dijkstra(int st){
    priority_queue<pair<ll,int>>pq;
    dis.assign(n+1, 1e18);
    vector<int>vis(n+1, 0);
    dis[st] = 0, pq.push(mpr(-dis[st], st));
    while(!pq.empty()){
        pair<ll,int> now = pq.top(); pq.pop();
        int x = now.second;
        if(vis[x])continue;
        vis[x] = 1;
        
        for(auto it : g0[x]){
            int u = it.to;
            if(dis[u] > dis[x] + it.e){
                dis[u] = dis[x] + it.e;
                pq.push(mpr(-dis[u], u));
            }
        }
    }
}

void init(){
    scc.init();
    for(int i=1;i<=n;i++){
        g[i].clear(), g0[i].clear(), h[i].clear();
        dp[i] = 0;
    }
    ed.clear();
}

void getdp(int x){
    if(x == scc.belong[n]){
        dp[x] = 0;
        return ;
    }
    if(dp[x] != 0)return ;

    ll r = -1e18;
    for(node now : h[x]){
        int u = now.to;
        getdp(u);
        r = max(r, dp[u] + now.p);
    }
    dp[x] = r;
}

void solve(){
    n=qr(),m=qr();
    init();
    for(int i=1;i<=m;i++){
        int u=qr(),v=qr(),e=qr(),p=qr();
        g0[u].pb({v,e,p});
    }
    dijkstra(1);

    for(int i=1;i<=n;i++){
        for(node it : g0[i]){
            int u = it.to;
            if(dis[u] == dis[i] + it.e){
                g[i].pb(it),
                ed.pb(edges{i,it.to,it.e,it.p});
            }
        }
    }

    scc.getscc();
    scc.deal();

    getdp(scc.belong[1]);
    printf("%lld %lld\n",dis[n],dp[scc.belong[1]]);
}

signed main(){
//    freopen("HDU7175.in","r",stdin);
    int te;
    scanf("%d",&te);
    while(te --)solve(); 

    return 0;
}
