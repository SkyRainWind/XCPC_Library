// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 205 * 205;

int n,m,ban;
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

const int dx[] = {-2,-2,-1,-1,1,1,2,2};
const int dy[] = {-1,1,-2,2,2,-2,1,-1};
int in(int x,int y){
	return x >=1 && x<=n && y>=1 && y<=n;
}
int ind(int x,int y){
	return (x-1)*n+y;
}

int bb[205][205];
signed main(){
	scanf("%d%d",&n,&ban);
	for(int i=1;i<=ban;i++){
		int x,y;scanf("%d%d",&x,&y);
		bb[x][y] = 1;
	}
	int s = n*n+1, t = n*n+2;
	nf.init(s, t);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if((i+j)&1){
			if(!bb[i][j])nf.add(s, ind(i,j), 1);
		}else{
			if(!bb[i][j])nf.add(ind(i, j), t, 1);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(((i+j)&1) && !bb[i][j]){
			for(int k=0;k<8;k++){
				int fi = i + dx[k], fj = j + dy[k];
				if(!in(fi, fj))continue;
				if(!bb[fi][fj])
					nf.add(ind(i, j), ind(fi, fj), inf);
			}
		}
	ll res = nf.dinic();
	cout << n*n-ban-res << '\n';

	return 0;
}

