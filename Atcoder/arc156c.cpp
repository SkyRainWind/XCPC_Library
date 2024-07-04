// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5005;

int n;
vector<int>g[maxn];
int de[maxn];
queue<int>Q;

void dfs(int x,int fat = 0){
	if(de[x] == 1)Q.push(x);
	for(int u : g[x])if(u!=fat){
		dfs(u, x);
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
		++ de[x], ++ de[y];
	}
	dfs(1);
	vector<int>ans(n+1, 0);
	while(!Q.empty()){
		int u = Q.front(); Q.pop(); 
		if(Q.empty()){
			ans[u] = u;
//			for(int it : g[u]){
//				-- de[it];
//				if(de[it] == 1)Q.push(it);
//			}
			break;
		}
		int v = Q.front(); Q.pop();
		ans[u] = v, ans[v] = u;
		for(int it : g[u]){
			-- de[it];
			if(de[it] == 1)Q.push(it);
		}
		for(int it : g[v]){
			-- de[it];
			if(de[it] == 1)Q.push(it);
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");

	return 0;
}

