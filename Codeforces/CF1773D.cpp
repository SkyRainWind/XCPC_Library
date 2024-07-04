// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3005;

int n,m,a[1005][1005];
struct ed{
	LL from,to,cap,flow,rev;
	ed(){}
	ed(LL from,LL to,LL cap,LL flow,LL rev):from(from),to(to),cap(cap),flow(flow),rev(rev){}
};
vector<ed>g[maxn];

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
inline int in(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;} 
inline int ind(int x,int y){return (x-1)*m+y;}

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
vector<pii>ed;
vector<int>lft,rgt; 
int vis[maxn];

void dfs(int x){
	vis[x] = 1;
	for(int i=0;i<g[x].size();i++){
		struct ed e = g[x][i];
		if(!vis[e.to] && e.flow == e.cap)dfs(e.to);
	}
}

map<int,int>mp;
int cc;

signed main(){
//	freopen("CF1773D.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char s[1005];
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			if(s[j] == '#')a[i][j] = 0;
			else a[i][j] = 1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(a[i][j] == 1)mp[ind(i, j)] = ++cc;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(a[i][j]){
			if((i%2 + j) & 1){
				for(int k=0;k<4;k++){
					int fi = i+dx[k], fj = j+dy[k];
					if(!in(fi, fj) || !a[fi][fj])continue;
					ed.pb(mpr(mp[ind(i, j)], mp[ind(fi, fj)]));
				}
			}
		}
	
	int cnt0=0, cnt1=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(a[i][j]){
			if((i%2 + j) & 1)++ cnt0, lft.pb(mp[ind(i, j)]);
			else ++cnt1, rgt.pb(mp[ind(i, j)]);
		}
	
	ll ans = 1ll*cnt0*(cnt0-1)/2 + 1ll*cnt1*(cnt1-1)/2;
	if(ans >= (ll)1e6)return printf("%d\n",(int)1e6), 0;
	
	int s = 2*cnt0+1, t = s+1;
	nf.init(s, t);
	for(int u : lft){
		for(int i : lft)g[i].clear(), vis[i] = 0;
		for(int i : rgt)g[i].clear(), vis[i] = 0;
		g[s].clear(), g[t].clear();
		vis[s] = vis[t] = 0;
		
		for(pii e : ed){
			if(e.first ^ u){
				nf.add(e.first, e.second, 1);
			}
		}
		for(int v : lft)if(u^v)nf.add(s, v, 1);
		for(int v : rgt)nf.add(v, t, 1);
		
		ll res = nf.dinic(), r=0;
		if(res != cnt0-1){
			ans += cnt1;
			continue;
		}
		dfs(t);
		for(int v : rgt)if(!vis[v])++ r;
		ans += r;
	}
	cout << min(ans, (ll)1e6) << '\n';

	return 0;
}

