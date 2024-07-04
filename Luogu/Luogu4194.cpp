// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 2e7, maxn = 1e5+5;

int n,m,a[205][205],srow[maxn],scol[maxn],rowid[maxn],colid[maxn],S,T;
int L,R;
int ind(int x,int y){return (x-1) * m + y;}

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
	void clear(){
		s=t=-1;
		for(int i=1;i<=n*m+n+m+10;i++)g[i].clear();
	}
	
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

int in[maxn], out[maxn], totn;
int check(int mid){
	nf.clear();
	memset(in, 0, sizeof in);memset(out, 0, sizeof out);
	// S -> row[1..n]
	for(int i=1;i<=n;i++){
		nf.add(S, rowid[i], 2 * mid);
		out[S] += (srow[i] - mid);
		in[rowid[i]] += (srow[i] - mid);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			nf.add(rowid[i], ind(i,j), R - L);
			out[rowid[i]] += L;
			in[ind(i, j)] += L;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			nf.add(ind(j, i), colid[i], R - L);
			out[ind(j, i)] += L;
			in[colid[i]] += L; 
		}
	}
	
	for(int i=1;i<=m;i++){
		nf.add(colid[i], T, 2 * mid);
		out[colid[i]] += scol[i] - mid;
		in[T] += scol[i] - mid;
	}
	
	nf.add(T, S, INF);
	out[T] += INF; in[T] += INF;
	
	int SS = totn+1, TT = totn + 2, lim = 0; 
	for(int i=1;i<=totn;i++){
		int cur = in[i] - out[i];
		if(cur > 0)nf.add(SS, i, cur),lim += cur;
		else nf.add(i, TT, -cur);
	}
	nf.init(SS, TT);
	
	int res = nf.dinic();
	if(res < lim)return 0;
	return 1;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	scanf("%d%d",&L,&R);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)srow[i] += a[i][j], scol[j] += a[i][j];
	
	S = n*m+1, T = n*m+2;
	for(int i=1;i<=n;i++)rowid[i] = n*m+i+2;
	for(int i=1;i<=m;i++)colid[i] = n*m+n+2+i; 
	totn = n*m+n+2+m;
	
//	printf("! %d\n",check(0));
	int l=0, r = 2e5, ans;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))ans = mid, r = mid-1;
		else l = mid+1;
	}
	printf("%d\n",ans);

	return 0;
}

