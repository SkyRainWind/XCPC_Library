#include<bits/stdc++.h>
#define ll long long

using namespace std;

#define B cerr<<"Break Point"<<endl;
#define pl(x) cerr<<#x<<' '<<"="<<' '<<(x)<<endl;
#define p(x) cerr<<#x<<' '<<"="<<' '<<(x)<<' ';

namespace io{
    const int SIZ=55;
    int que[SIZ],op,qr;
    char ch;
    template<class I>
    void read(I &w){
        ch=getchar(),op=1,w=0;
        while(!isdigit(ch)){if(ch=='-') op=-1;ch=getchar();}
        while(isdigit(ch)){w=w*10+ch-'0';ch=getchar();}w*=op;
    }
    template<typename T,typename... Args>
    void read(T& t,Args&... args){read(t);read(args...);}
}
using io::read;

#define int long long
#define LL long long

const LL N=100010,inf=1e17;
int low[N],dfn[N],stk[N],siz[N],scc[N];
bool ins[N];
LL dis[N],dp[N],in[N],n,m,s,dfncnt,sc,tp;
bool h[N];
vector<int> a[N],w[N],ph[N];
struct edge{
    int v;
    ll w,p;
};
vector<edge> BeforeTarjan[N],AfterTarjan[N];
struct node{
    LL n,w;
};
bool operator > (node a,node b){
    return a.w>b.w;
}
priority_queue<node,vector<node>,greater<node> > p;
queue<int> q;
void dij(){
    memset(dis,63,sizeof(dis));
    memset(h,0,sizeof(h));
    dis[1]=0;
    while(p.size()) p.pop();
    p.push((node){1,0});
    while(p.size()){
        node x=p.top(); p.pop();
        if(h[x.n]) continue;
        int u=x.n;
        h[u]=1; 
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i],we=w[u][i];
            if(dis[v]>dis[u]+we){
                dis[v]=dis[u]+we;
                p.push((node){v,dis[v]});
            }
        }
    }
}
void Tarjan(int u){
    low[u]=dfn[u]=++dfncnt;
    stk[++tp]=u,ins[u]=true;
    for(auto i:BeforeTarjan[u]){
        int v=i.v;
        ll w=i.w,p=i.p;
        if(!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++sc;
        while(stk[tp]!=u){
            scc[stk[tp]]=sc;
            ++siz[sc];
            ins[stk[tp]]=false;
            --tp;
        }
        scc[stk[tp]]=sc;
        ++siz[sc];
        ins[stk[tp]]=false;
        --tp;
    }
}
void topo(){
    memset(dp,0,sizeof(dp));
    memset(in,0,sizeof(in));
    memset(h,0,sizeof(h));
    for(int i=1;i<=n;++i) BeforeTarjan[i].clear(),AfterTarjan[i].clear();
    for(int u=1;u<=n;u++){
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i],we=w[u][i],pe=ph[u][i];
            if(dis[u]+we==dis[v] ){
                BeforeTarjan[u].push_back({v,we,pe});
            }
        }
    }
    tp=0,sc=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(ins,0,sizeof(ins));
    memset(scc,0,sizeof(scc));
    memset(in,0,sizeof(in));
    Tarjan(1);
    for(int u=1;u<=n;++u){
        for(auto i:BeforeTarjan[u]){
            int v=i.v;
            ll w=i.w,p=i.p;
            if(scc[u]!=scc[v]){
                AfterTarjan[scc[u]].push_back({scc[v],w,p});
                ++in[scc[v]];
            }
        }
    }
    //
    while(q.size()) q.pop();
    q.push(scc[1]);
    while(q.size()){
        int u=q.front();
        h[u]=1;
        q.pop();
        for(int i=0;i<AfterTarjan[u].size();i++){
            int v=AfterTarjan[u][i].v,we=AfterTarjan[u][i].w,pe=AfterTarjan[u][i].p;
            if(pe) in[v]--;
            dp[v]=max(dp[v],dp[u]+pe);
            if(!in[v] && !h[v]){
                q.push(v);
               //h[v]=1;
           }
        }
    }
}
signed main(){
//	freopen("HDU7175.in","r",stdin);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int x,y,z,pp;
            cin>>x>>y>>z>>pp;
            a[x].push_back(y);
            w[x].push_back(z);
            ph[x].push_back(pp);
        }
        dij();
        topo();
        cout<<dis[n]<<" "<<dp[scc[n]]<<endl;
        for(int i=1;i<=n;i++){
            a[i].clear();
            w[i].clear();
            ph[i].clear();
        }
    }
    return 0;
}
