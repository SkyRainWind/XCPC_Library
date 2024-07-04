// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e18, INF = 0x3f3f3f3f, maxn = 200005;

int n,m,s,t;
struct ed{
	LL from,to,cap,flow,rev;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev):from(from),to(to),cap(cap),flow(flow),rev(rev){}
};
vector<ed>g[maxn];

struct netflow{
	int cur[maxn]; 
	int d[maxn], q[maxn], hd, tl;
	int s, t;	// 源 汇 
	
	netflow(){s=t=-1;}
	
	void init(int s0,int t0){
		s = s0, t = t0;
	}

	void add(int x,int y,int v){
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

signed main(){
	scanf("%lld%lld",&m,&n);
	s = 0, t = n + m + 1;
	LL ans = 0;
	for(int i=1;i<=m;i++){
		int x;scanf("%lld",&x);
		int tt;
		nf.add(s, i, x);
		while(scanf("%lld",&tt), tt){
			nf.add(i, m+tt, 1ll << 62);
		}
		ans += x;
	}
	nf.init(s, t);
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		nf.add(m+i, t, x);
	}
	ans -= nf.dinic();
	printf("%lld\n",max(ans, 0ll));

	return 0;
}
