// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,m;
struct ed{
	LL from,to,cap,flow,rev;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev):from(from),to(to),cap(cap),flow(flow),rev(rev){}
};
vector<ed>g[maxn];
vector<int>og[maxn];
int col[maxn];

struct netflow{
	int cur[maxn]; 
	int d[maxn], q[maxn], hd, tl;
	int s, t;	// 源 汇 
	
	netflow(){s=t=-1;}
	
	void init(int s0,int t0){
		s = s0, t = t0;
	}

	void add(int x,int y,LL v){
		g[x].push_back(ed(x,y,v,0,g[y].size()));
		g[y].push_back(ed(y,x,0,0,g[x].size() - 1));
	}
	
	int bfs(){
		memset(d,0, sizeof d);
		hd = tl = 0;
		q[tl ++] = s;
		d[s] = 1;
		while(hd != tl){
			int now = q[hd ++];
			for(int i = 0;i<g[now].size();i++){
				ed &e = g[now][i];
				if(!d[e.to] && e.cap > e.flow)d[e.to] = d[now] + 1, q[tl ++] = e.to;
			}
		}
		return d[t];
	}
	
	LL dfs(int now,LL rem){	// rem 当前流量 
		if(now == t || !rem)return rem;
		LL flow = 0;
		for(int &i = cur[now]; i < g[now].size();i ++){
			ed &e = g[now][i];
				// 分层图 & 残量不为0 
			if(d[e.to] == d[now] + 1 && e.cap > e.flow){
				LL f = dfs(e.to, min(rem, e.cap - e.flow));
				rem -= f, flow += f, e.flow += f, g[e.to][e.rev].flow -= f;
			}
			if(!rem)break;
		}
		if(rem)d[now] = -1;
		return flow;
	}
	
	LL dinic(){
		assert(s!=-1);
		LL flow = 0;
		while(bfs()){
			memset(cur, 0, sizeof cur);
			flow += dfs(s, 1ll << 62);
		}
		return flow;
	}
}nf;

pii edge[maxn];
vector<int>ng[maxn], h[maxn];
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
		for(int i=0;i<g[x].size();i++){
			int u = g[x][i].to;
			if(g[x][i].flow == g[x][i].cap)continue;
//			printf("[%d,%d] %d\n",x,u,g[x][i].flow);
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
};
struct _scc scc;

void dfs(int x,int c){
	col[x] = c;
	for(int u : og[x])if(!col[u]){
		dfs(u, 3-c);
	}
}

signed main(){
//	freopen("Luogu3731.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		og[x].pb(y), og[y].pb(x);
	}
	for(int i=1;i<=n;i++)if(!col[i])dfs(i,1);
	int s = n+2, t = n+1;
	nf.init(s, t);
	
	int ec = 0;
	for(int i=1;i<=n;i++)if(col[i] == 1){
		for(auto it : og[i]){
			int x = i, y = it;
//			printf("%d %d %d\n",x,y,col[x]+col[y]);
			nf.add(x,y,1);
			ng[x].pb(y);
//			printf("(%d,%d)\n",x,y);
			edge[++ec] = mpr(x, y);
		}
	}
	
	for(int i=1;i<=n;i++)
		if(col[i] == 1)nf.add(s, i, 1);
		else nf.add(i, t, 1);

	ll res = nf.dinic();
	scc.getscc();

	vector<pii>ans;
	for(int i=1;i<=n;i++)if(col[i] == 1)
		for(int j=0;j<g[i].size();j++){
			ed u = g[i][j];
//			printf("! %d\n",u.flow);
			if(u.flow == 1){
				if(scc.belong[i] != scc.belong[u.to]){
					ans.emplace_back(min(i,(int)u.to), max(i,(int)u.to)); 
//				printf("%d %d\n",i,u.to);
			}
		}
	}
	
	sort(ans.begin(), ans.end(), [&](pii a,pii b){
		return a.first == b.first ? a.second < b.second : a.first < b.first;
	});
	printf("%d\n",ans.size());
	for(auto u : ans)
		printf("%d %d\n",u.first,u.second);

	return 0;
}

