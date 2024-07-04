// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert> 
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>
 
using namespace std;
 
typedef long long LL;
#define int LL
 
const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6 + 5;
 
int a[maxn], b[maxn], c[maxn];
int n,m,L[maxn],R[maxn];
 
struct ed{
	LL from,to,cap,flow,rev;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev):from(from),to(to),cap(cap),flow(flow),rev(rev){}
};
vector<ed>g[maxn];
 
struct netflow{
	int cur[maxn]; 
	int d[maxn], q[20000005], hd, tl;
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
			flow += dfs(s, 0x3f3f3f3f3f3f3f3f);
		}
		return flow;
	}
}nf;
 
int f(int i,int j){
	return a[i] * j * j + b[i] * j + c[i];
}
 
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	}
	int S = (n+1) * 202, T = (n+1) * 202 + 1, big = 1000000000000;
	nf.init(S, T);
	for(int i=1;i<=n;i++){
		int l, r;scanf("%lld%lld",&l,&r);
		nf.add(S, l + (i) * 202, 0x3f3f3f3f3f3f3f3f);
		for(int j=l;j<=r;j++){
			nf.add(j + (i) * 202, j + 1 + (i) * 202, big - f(i, j));
		}
		nf.add(r + 1 + (i)*202, T, 0x3f3f3f3f3f3f3f3f);
		L[i] =l, R[i] = r;
	}
	for(int i=1;i<=m;i++){
		int u,v,d;scanf("%lld%lld%lld",&u,&v,&d);
		for(int j=L[u];j<=R[u]+1;j++){	// x_v >= x_u - d j = u
			int xv = j - d;
			if(xv >= L[v] && xv <= R[v] + 1){
				nf.add(j + (u) * 202, xv + (v) * 202, 0x3f3f3f3f3f3f3f3f);
			}
		}
	}
	printf("%lld\n",1ll * big * n - nf.dinic());
 
	return 0;
}

