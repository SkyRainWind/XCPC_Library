// by SkyRainWind
// 求有源汇？连一条 T->S c = inf 的边（注意不是超级源汇！） 
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 10005;

int n,m;
struct ed{
	LL from,to,cap,flow,rev;
	int id, low, ad;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev,int id,int low,int ad):from(from),to(to),cap(cap),flow(flow),rev(rev),id(id),low(low),ad(ad){}
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

	void add(int x,int y,LL v,int id,int low,int gg){
		g[x].push_back(ed(x,y,v,0,g[y].size(),id,low,gg));
		g[y].push_back(ed(y,x,0,0,g[x].size() - 1,id,low,0));
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
int in[maxn], out[maxn], ans[maxn];

signed main(){
	int s0, t0;
	scanf("%d%d%d%d",&n,&m,&s0,&t0);
	int s = 0, t = n+1;
	for(int i=1;i<=m;i++){
		int x, y, lw, up;
		scanf("%d%d%d%d",&x,&y,&lw,&up);
		nf.add(x, y, up - lw, i, lw, 1);
		out[x] += lw;
		in[y] += lw;
	}
	
	int lim = 0;
	for(int i=1;i<=n;i++){
		int cur = in[i] - out[i];
			// id = 0，直接不会纳入最后计算 
		if(cur > 0)nf.add(s, i, cur, 0, 0, 0), lim += cur;
		else nf.add(i, t, -cur, 0, 0, 0);
	}
	nf.init(s, t);
	nf.add(t0, s0, inf, 0, 0, 0);
	
	int res = nf.dinic();
//	printf("%d\n",lim);
	if(res < lim)puts("please go home to sleep");
	else{
		nf.init(s0, t0);
		printf("%d\n",nf.dinic());
	}

	return 0;
}
