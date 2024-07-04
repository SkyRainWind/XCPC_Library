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

unordered_map<int,int>mp[maxn];
int n,m;
vector<int>g[maxn];
int de[maxn],dis[maxn],vis[maxn];
pii nd[maxn];

signed main(){
	memset(dis,-0x3f,sizeof dis);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(mp[x].count(y))continue;
		mp[x][y]=1;
		g[x].pb(y);
		++ de[y];
	}
	for(int i=1;i<=n;i++){
		if(!de[i]){
			queue<int>Q;
			Q.push(i);
			dis[i] = 0;
			while(!Q.empty()){
				int u = Q.front(); Q.pop();
				for(int v : g[u]){
					if(dis[v] < dis[u] + 1){
						dis[v] = dis[u] + 1;
						if(!--de[v])
							Q.push(v);
					}
				}
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)nd[i] = mpr(dis[i], i);
	sort(nd+1,nd+n+1,[&](pii a,pii b){
		return a.first < b.first;
	});
	vector<int>per(n + 1);
	for(int i=2;i<=n;i++){
		if(nd[i].first != nd[i-1].first + 1){
			puts("No");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)per[nd[i].second] = nd[i].first + 1;
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%d ",per[i]);puts("");

	return 0;
}

