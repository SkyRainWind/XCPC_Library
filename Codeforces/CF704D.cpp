// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;
#define int ll

const int inf = 1e18, INF = 0x3f3f3f3f, maxn = 5e5 + 5;

struct ed{
	LL from,to,cap,flow,rev;
	int id;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev,int id):from(from),to(to),cap(cap),flow(flow),rev(rev),id(id){}
};
vector<ed>g[maxn];
int n,m,r,b,c1,c2;

struct netflow{
	int cur[maxn*6]; 
	int d[maxn*2], q[maxn*2], hd, tl;
	ll in[maxn], out[maxn];
	int s, t;	// 源 汇 
	
	netflow(){s=t=-1;}
	
	void clear(){
		s = t = -1;
		for(int i=1;i<=n+m+10;i++)g[i].clear(), in[i] = out[i] = 0;
	}
	
	void init(int s0,int t0){
		s = s0, t = t0;
	}

	void add(int x,int y,LL v,int id=0){
		g[x].push_back(ed(x,y,v,0,g[y].size(),id));
		g[y].push_back(ed(y,x,0,0,g[x].size() - 1, 0));
	}
	
	void adde(int x,int y,LL l,LL r,int id=0){	// x->y [l,r]
		if(l > r){puts("-1");exit(0);}
		add(x, y, r-l,id);
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
			if(i > c1 && i <=n)continue;
			if(i > n+c2 && i<=2*n)continue;
			ll cur = in[i] - out[i];
			if(cur > 0)add(S, i, cur), lim += cur;
			else add(i, T, -cur);
		}
		add(T0, S0, 1e18);
		init(S, T);
		LL res = dinic();
		if(res < lim)return -1;
		init(S0, T0);
		return dinic();
	}
}nf;
int x[maxn], y[maxn];
map<int,int>newx, newy, mapx, mapy;
int bound1[maxn], bound2[maxn];
int op[maxn], pos[maxn];
int visx[maxn], visy[maxn];
int ok[maxn];

signed main(){
	int S0, T0, S, T;
	int fg = 0;
	scanf("%lld%lld%lld%lld",&n,&m,&r,&b); 
	if(r > b)swap(r, b), fg = 1;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		++ newx[x[i]];++ newy[y[i]];
		bound1[i]=bound2[i] = 1e18;
	}
	for(auto u : newx) mapx[u.first] = ++c1;
	for(auto u : newy) mapy[u.first] = ++c2;
	for(int i=1;i<=n;i++)x[i] = mapx[x[i]], y[i] = mapy[y[i]];
	S0 = 2 * n+1, T0 = 2*n + 2;S = 2*n+3,T=2*n+4;
	for(int i=1;i<=m;i++){
		int d;
		scanf("%lld%lld%lld",&op[i],&pos[i],&d);
		if(op[i] == 1){bound1[mapx[pos[i]]] = min(bound1[mapx[pos[i]]], d);}
		else{bound2[mapy[pos[i]]] = min(bound2[mapy[pos[i]]], d);}
	}
	
	for(int i=1;i<=m;i++){
		if(op[i] == 1){	// x=xy, <=d
			if(visx[mapx[pos[i]]])continue;
			int cnt = newx[pos[i]], d = bound1[mapx[pos[i]]];
			int L = (cnt-d+1)/2, R = (cnt+d) / 2;
			nf.adde(S0, mapx[pos[i]], L, R);
			visx[mapx[pos[i]]] = 1;
		}else{
			if(visy[mapy[pos[i]]])continue;
			int cnt = newy[pos[i]], d = bound2[mapy[pos[i]]];
			int L = (cnt-d+1)/2, R = (cnt+d)/2;
			nf.adde(n + mapy[pos[i]], T0, L, R);
			visy[mapy[pos[i]]] = 1;
		}
	}
	for(int i=1;i<=c1;i++)
		if(!visx[i])nf.adde(S0, i, 0, 1e18);
	for(int i=1;i<=c2;i++)
		if(!visy[i])nf.adde(n + i, T0, 0, 1e18);
	for(int i=1;i<=n;i++)
		nf.adde(x[i], n + y[i], 0, 1, i);
		
	ll res = nf.pflow(S0, T0, S, T, 2*n+2);
	if(res == -1)return puts("-1"), 0;
	printf("%lld\n",1ll * res * r + 1ll * (n-res) * b);
	for(int i=1;i<=c1;i++){
		for(ed u : g[i])
			if(u.id)ok[u.id] = u.flow;
	}
	for(int i=1;i<=n;i++)
		if(ok[i] ^ fg)putchar('r');
		else putchar('b');

	return 0;
}

