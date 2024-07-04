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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=200005;

int n,a[maxn], b[maxn];
int cnt=0;
int notpm[200005], pm[200005], pcnt=0;

struct ed{
	LL from,to,cap,flow,rev;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev):from(from),to(to),cap(cap),flow(flow),rev(rev){}
};
vector<ed>g[maxn];

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=200000;i++){
		if(!notpm[i]){
			pm[++ pcnt] = i;
		}
		for(int j=1;j<=pcnt && i * pm[j] <= 200000;j++){
			notpm[i * pm[j]] = 1;
			if(i % pm[j] == 0)break;
		}
	}
}

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

signed main(){
//	freopen("Luogu5771.in","r",stdin);
	xxs();
	scanf("%d",&n);
	
	int fg = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i] == 1 && fg)continue;
		b[++ cnt] = a[i];
		if(a[i] == 1)fg = 1;
	}
	n = cnt;
	nf.init(n + 2, n + 1);
	
	memcpy(a, b, sizeof a);
	for(int i=1;i<=n;i++){
		if(b[i] & 1){
			nf.add(n + 2, i, 1);
		}else nf.add(i, n+1, 1);
	}
	for(int i=1;i<=n;i++)if(a[i]&1)
		for(int j=1;j<=n;j++)if(a[j]%2==0)
			if(!notpm[a[i] + a[j]]){
				nf.add(i, j, 1);
			}
	printf("%lld\n",n - nf.dinic());

	return 0;
}

