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

vector<int>g[maxn], h[maxn];
int min_cost[maxn],max_cost[maxn],a[maxn];
pii ed[maxn*10];
int m,n,_m,de[maxn],vis[maxn];
struct _scc{
	// 存图 g[] 缩点之后在 h[]
	// ed[] 保存原图的 m 个有向边 
	int dfn[maxn], low[maxn], dfs_clock;
	int stk[maxn], tp = 0, belong[maxn], tot=0, sz[maxn];
	// belong[i] i 属于哪个强连通块 tot 块数（新的n）sz 每个块的大小 
	_scc(){memset(dfn,0,sizeof dfn);}
	
	void tarjan(int x){
		dfn[x] = low[x] = ++ dfs_clock; 
		stk[++ tp] = x;
		for(int u : g[x]){
			if(!dfn[u]){
				tarjan(u);
				low[x] = min(low[x], low[u]);
			}else if(!belong[u])
				low[x] = min(low[x], dfn[u]); 
		}
		if(low[x] == dfn[x]){
			belong[x] = ++tot;
			min_cost[tot] = a[x];
			max_cost[tot] = a[x];
			++sz[tot];
			while(stk[tp] != x){
				++sz[tot];
				belong[stk[tp]] = tot;
				min_cost[tot] = min(min_cost[tot], a[stk[tp]]);
				max_cost[tot] = max(max_cost[tot], a[stk[tp]]);
				-- tp;
			}
			-- tp;
		}
	}
	
	void getscc(){
		for(int i=1;i<=n;i++)
			if(!dfn[i])tarjan(i);
	}
	
	void deal(){	// 缩点 
		for(int i=1;i<=m;i++){
			int x = ed[i].first, y = ed[i].second;
			if(belong[x] != belong[y]){
				h[belong[x]].push_back(belong[y]),
				++ de[belong[y]];
			}
		}
	}
	
	int ans = 0, s, t;
	int dfs(int x){
		if(x == t){
			ans = max(ans, max_cost[x] - min_cost[x]);
			return 1;
		}
		vis[x] = 1;
		int fg = 0;
		for(int u : h[x])if(!vis[u]){
			int tt = dfs(u);
			if(tt == 1){
				fg = 1;
				max_cost[x] = max(max_cost[x], max_cost[u]);
			}
		}
		if(fg)ans = max(ans, max_cost[x] - min_cost[x]);
			// min_cost[x] not updated, max_cost[x] refer to all descendent 
		return fg;
	}
	
	void solve(){
		s = belong[1], t = belong[n];
		dfs(s);
		cout << ans << '\n';
	}
};
struct _scc scc;

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

signed main(){
//	freopen("1073.in","r",stdin);
	n=qr(),_m=qr();
	for(int i=1;i<=n;i++)a[i]=qr();
	for(int i=1;i<=_m;i++){
		int x=qr(),y=qr(),z=qr();
		if(z==1)g[x].pb(y),ed[++m]=mpr(x,y);
		else g[x].pb(y),g[y].pb(x),ed[++m]=mpr(x,y),ed[++m]=mpr(y,x);
	}
	scc.getscc();
	scc.deal();
	scc.solve();

	return 0;
}

