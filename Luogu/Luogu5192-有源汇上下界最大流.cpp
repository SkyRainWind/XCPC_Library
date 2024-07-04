// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 2e7, maxn = 2e5+5;

int n,m,gi[maxn];
struct ed{
	LL from,to,cap,flow,rev;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev):from(from),to(to),cap(cap),flow(flow),rev(rev){}
};
vector<ed>g[maxn];

struct netflow{
	int cur[maxn]; 
	int d[maxn], q[maxn], hd, tl;
	int in[maxn], out[maxn];
	int s, t;	// 源 汇 
	
	netflow(){s=t=-1;}
	
	void clear(){
		s = t = -1;
		for(int i=1;i<=n+m+10;i++)g[i].clear(), in[i] = out[i] = 0;
	}
	
	void init(int s0,int t0){
		s = s0, t = t0;
	}

	void add(int x,int y,LL v){
		g[x].push_back(ed(x,y,v,0,g[y].size()));
		g[y].push_back(ed(y,x,0,0,g[x].size() - 1));
	}
	
	void adde(int x,int y,int l,int r){	// x->y [l,r]
		add(x, y, r-l);
		out[x] += l; in[y] += l;
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
	
	LL pflow(int S0, int T0, int S, int T, int point){	// possible flow
		// S0 T0 源点汇点 ST 超源超汇 point 有多少点 
		LL lim = 0;
		for(int i=1;i<=point;i++){
			int cur = in[i] - out[i];
			if(cur > 0)add(S, i, cur), lim += cur;
			else add(i, T, -cur);
		}
		add(T0, S0, inf);
		init(S, T);
		LL res = dinic();
		if(res < lim)return -1;
		init(S0, T0);
		return dinic();
	}
}nf;
int S0, T0, S, T;

signed main(){
	int ks = 0;
	while(scanf("%d%d",&n,&m)!= EOF){
		if(++ks >= 2)puts("");
		nf.clear();
		S = n+m+3, T = n+m+4;
		S0 = n+m+1, T0 = n+m+2;
		for(int i=1;i<=m;i++)scanf("%d",&gi[i]), nf.adde(i, T0, gi[i], INF);
		for(int i=1;i<=n;i++){
			int day = i+m;
			int c,d;scanf("%d%d",&c,&d);
			while(c --){
				int t, l, r;
				scanf("%d%d%d",&t,&l,&r);
				// (day, t) [l,r]
				++ t;
				nf.adde(day, t, l, r);
			}
			nf.adde(S0, day, 0, d);
		}
		LL res=nf.pflow(S0, T0, S, T, n+m+2);
		if(res == -1)puts("-1");
		else printf("%lld\n",res);
	}

	return 0;
}

