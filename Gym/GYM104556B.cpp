// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<ll,ll>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,m,q,r[maxn],b[maxn];
vector<pii>g[maxn];
int st[maxn * 5][22],seq[maxn],cnt,dep[maxn],isr[maxn];
ll dis[maxn],cost[maxn];

void dfs(int x,int fat=0){
	dep[x] = dep[fat] + 1;
	st[++cnt][0] = x; seq[x] = cnt;
	for(auto it : g[x])if(it.first!=fat){
		dis[it.first] = dis[x] + it.second;
		if(isr[it.first])cost[it.first] = 0;
		else cost[it.first] = cost[x] + it.second;
		dfs(it.first,x);
		st[++cnt][0] = x;
	}
}

int getlca(int x,int y){
	if(seq[x] > seq[y])swap(x, y);
	int lg = (int)floor(log(1.0 * (seq[y]-seq[x]+1)) / log(2.0));
	int t1 = st[seq[x]][lg], t2 = st[seq[y]-(1<<lg)+1][lg];
	if(dep[t1] < dep[t2])return t1;
	return t2;
}

void solve(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)g[i].clear(), isr[i] = 0;
	for(int i=1;i<=m;i++)scanf("%d",&r[i]), isr[r[i]] = 1;
	for(int i=1;i<n;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].pb(mpr(v,w)), g[v].pb(mpr(u,w));
	}
	cnt=0;
	dfs(1);
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=cnt;i++){
			if(dep[st[i][j-1]] < dep[st[i+(1<<(j-1))][j-1]])
				st[i][j] = st[i][j-1];
			else st[i][j] = st[i+(1<<(j-1))][j-1];
		}
	while(q --){
		int k;scanf("%d",&k);
		for(int i=1;i<=k;i++)scanf("%d",&b[i]);
		if(k == 1){
			puts("0");
			continue;
		}
		sort(b+1,b+k+1,[&](int p,int q){return cost[p] > cost[q];});
		int ans = -1;ll res=cost[b[1]],mx=0;
		for(int i=1;i<k;i++){
			if(~ans){
				ans = getlca(ans,b[i]);
			}
			else ans = b[i];
			mx = max(mx, dis[b[i]]);
			res = min(res, max(mx - dis[ans], cost[b[i+1]]));
		}
		mx=max(mx,dis[b[k]]);ans=getlca(ans,b[k]);
		res=min(res,mx-dis[ans]);
		printf("%lld\n",res);
	}
//	printf("%d %d\n",getlca(2,4),getlca(1,3));
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

