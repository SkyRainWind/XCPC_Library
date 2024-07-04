// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int INF = 0x3f3f3f3f,maxn=805;
const ll inf = 1e18;

// dp[i][j](1,2) 表示到了 i 点，挣的最多的在 j，最小次数、剩余的最大钱 

int n,m,p;
vector<pii>g[805];
int w[maxn];

struct node{
	ll perf, rest;
};
node dp[maxn][maxn];

struct state{
	node st;
	int x,best;
};

bool operator < (state a,state b){
	if(a.st.perf == b.st.perf)return !(a.st.rest > b.st.rest);
	return !(a.st.perf < b.st.perf);
}

int cmp(node a,node b){
	if(a.perf == b.perf)return a.rest > b.rest;
	return a.perf < b.perf;
}

void dij(){
	priority_queue<state>pq;
	dp[1][1] = node{0,p};
	pq.push(state{dp[1][1],1,1});
	while(!pq.empty()){
		state u = pq.top(); pq.pop();
		if(dp[u.x][u.best].perf != u.st.perf ||
			dp[u.x][u.best].rest != u.st.rest)continue;
		
		for(auto it : g[u.x]){
			int cost = it.second, v = it.first;
			// (u.x,v) cost
			int nbest = u.best;
			if(w[nbest] < w[v])nbest = v;
			ll ned = cost - dp[u.x][u.best].rest;
			ll times = 0, nrest = dp[u.x][u.best].rest;
			if(ned > 0){
				times = (ned - 1) / w[u.best] + 1;
				nrest = dp[u.x][u.best].rest + 1ll * times * w[u.best] - cost;
			}else nrest -= cost;
			node ndp = dp[u.x][u.best];
			ndp.perf += times;
			ndp.rest = nrest;
			
			if(cmp(ndp, dp[v][nbest])){
				dp[v][nbest] = ndp;
				pq.push(state{ndp, v, nbest});
			}
		}
	}
}

void solve(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]), g[i].clear();
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].pb(mpr(y, z));
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dp[i][j] = node{inf,inf};
	dij();
	
	ll ans = inf;
	for(int i=1;i<=n;i++)ans = min(ans, dp[n][i].perf);
	if(ans == inf)puts("-1");
	else printf("%lld\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

