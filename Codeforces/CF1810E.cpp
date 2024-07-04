// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,m,a[maxn],vis[maxn],fa[maxn], sz[maxn];
vector<int>g[maxn];

int find(int x){
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void un(int x,int y){
	int fx = find(x), fy = find(y);
	if(fx == fy)return ;
//	if(sz[fx] < sz[fy])swap(fx, fy);
	swap(fx, fy);
	fa[fy] = fx;
	sz[fx] += sz[fy];
}

void deal(int x){
	priority_queue<pii>pq;
	pq.push(mpr(0,x));
	
	while(!pq.empty()){
		int dis=-pq.top().first, u = pq.top().second;pq.pop();
		if(vis[u] == x)continue;
		vis[u] = x;
		if(a[u] > sz[find(x)])return ;
		
		if(a[u] <= sz[find(x)]){
//			printf("(%d,%d)\n",x,u);
			un(u, x);
			for(int v : g[u]){
				if(vis[v] != x){
					pq.push(mpr(-a[v], v));
				}
			}
		}
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), vis[i] = 0, fa[i] = i, sz[i] = 1;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	
	int r = 0;
	for(int i=1;i<=n;i++)
		if(a[i] == 0 && !vis[i]){
			deal(i);
			if(sz[i] == n){
				r = 1;
				break;
			}
		}
	puts(r ? "YES" : "NO");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve(); 

	return 0;
}

