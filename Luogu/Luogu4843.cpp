// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+ 5;

int n;
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
		init(T0, S0);
		return inf - dinic();
	}
}nf;
int S0, T0, S, T;
int in[maxn], out[maxn];

signed main(){
	scanf("%d",&n);
	S0 = n+1, T0 = n+2, S = n+3, T = n+4; 
	for(int i=1;i<=n;i++){
		int tt;scanf("%d",&tt);
		while(tt --){
			int x;scanf("%d",&x);
			nf.adde(i,x,1,inf);
			++ out[i], ++ in[x];
		}	
	}
	for(int i=1;i<=n;i++){
		if(in[i] == 0)nf.adde(S0, i, 0, inf);
		if(out[i] == 0)nf.adde(i, T0, 0, inf);
	}
	ll res = nf.pflow(S0, T0, S, T, n+2);
	cout << res << '\n';

	return 0;
}

