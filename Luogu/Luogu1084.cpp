// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 + 5;

inline void read(int &x)
{
	int a=0;
	char c=getchar();
	while(c>57 or c<48) c=getchar();
	while(47<c and c<58)
	{
		a=a*10+c-48;
		c=getchar();
	}
	x=a;
}

int n;
vector<pii>g[maxn];
int m,pos[maxn];
int dep[maxn],fa[maxn][23];
ll dist[maxn][23],vis[maxn];

void dfs(int x,int fat=0){
	dep[x] = dep[fat] + 1;
	for(pii u : g[x])if(u.first != fat){
		dist[u.first][0] = u.second;
		fa[u.first][0] = x;
		dfs(u.first, x);
	}
}

vector<int>sons;
vector<ll>backup[maxn];
int rtson[maxn];
int dfs0(int x,int fat=0){
	int fg = 1;
	for(pii u : g[x])if(u.first != fat){
		int curst = dfs0(u.first, x);
		fg &= curst;
	}
	if(x != 1 && g[x].size() == 1)fg = 0;
	fg |= vis[x];
	
	if(fat == 1)sons.push_back(x), rtson[x] = fg;
	return fg;
}

int check(ll lim){
	sons.clear();
	for(int i=1;i<=n;i++)vis[i] = rtson[i] =0, backup[i].clear();
	
	int se=0;
	for(int i=1;i<=m;i++){
		int cur = pos[i];
//		if(dep[cur] > 2)debug();
		ll curt = lim;
		for(int j = 16;j>=0;j--)
			if(dep[fa[cur][j]] >= 2){
				if(curt - dist[cur][j] >= 0){
//					debug();
					curt -= dist[cur][j];
					cur = fa[cur][j];
				}
			}
		if(dep[cur] > 2){
			vis[cur]=1;
		}else if(dist[cur][0] >= curt){
			vis[cur]=1;
		}else{
			backup[cur].push_back(curt-dist[cur][0]);
			++se;
		}
	}
	dfs0(1); 
	vector<pii>tt;
//	cerr<<sons.size()<<'\n';
	
	vector<ll>ret;
	vector<ll>uncapture;
	for(int u : sons){
		if(rtson[u]){
			for(ll v : backup[u])
				ret.push_back(v);
		}else{
			if(backup[u].size() == 0){
//			cerr<<u<<'\n';
				uncapture.push_back(dist[u][0]);
				continue;
			}
			rtson[u] = 1;
			ll mn=1e18,mnid=-1;
			for(int i=0;i<backup[u].size();i++){
				ll v=backup[u][i];
				if(v < mn && v < dist[u][0])mn = v, mnid = i;
			}
			for(int i=0;i<backup[u].size();i++)if(mnid!=i){
				ll v = backup[u][i];
				ret.push_back(v);
			}
			if(mnid==-1)uncapture.push_back(dist[u][0]);
//			cerr<<ret.size() << ' '<<backup[u].size()<<'\n';
		}
	}
	if(uncapture.size() == 0)return 1;
	sort(ret.begin(),ret.end());
	sort(uncapture.begin(), uncapture.end());
	
//	cerr<<ret.size()<<' '<<uncapture.size()<<'\n';
	int p1=0,p2=0;
	for(;p1<ret.size();p1++){
//		cerr<<ret[p1]<<' '<<uncapture[p2]<<'\n';
		if(ret[p1] >= uncapture[p2]){
			++ p2;
			if(p2 == uncapture.size())return 1;
		}
	}
//	cerr<<p2<<' '<<ret.size()<<'\n';
	return 0;
}

signed main(){
//	freopen("1084-2.in","r",stdin);
//	freopen("Luogu1084.out","w",stdout);
	ll r=0;
	read(n);
	for(int i=1;i<=n-1;i++){
		int x,y,z;read(x);read(y);read(z);
		g[x].push_back(mpr(y, z));g[y].push_back(mpr(x,z));
		r+=z;
	}
	read(m);
	for(int i=1;i<=m;i++)read(pos[i]);
	dfs(1);
	for(int j=1;j<=16;j++)
		for(int i=1;i<=n;i++)
			fa[i][j] = fa[fa[i][j-1]][j-1];
	for(int j=1;j<=16;j++)
		for(int i=1;i<=n;i++)
			if(fa[i][j])dist[i][j] = dist[i][j-1] + dist[fa[i][j-1]][j-1];
			
//	printf("%d\n",check(1000));return 0;
	ll l=0, ans = -1;
	while(l <= r){
		ll mid = l+r>>1;
		if(check(mid))r = mid-1, ans = mid;
		else l = mid+1;
	}
	printf("%lld\n",ans);

	return 0;
}

