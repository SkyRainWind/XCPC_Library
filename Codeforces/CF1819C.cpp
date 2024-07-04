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

int n;
vector<int>g[maxn];
int lmx, be;

void dfs(int x,int fat=0,int dep=0){
	if(lmx < dep){lmx = dep, be = x;}
	for(int u : g[x])if(u!=fat){dfs(u,x,dep+1);}
}

int dep[maxn], pre[maxn], dia[maxn];
vector<int>di,leaf[maxn];
void dfs2(int x,int fat=0){
	dep[x] = dep[fat] + 1;
	for(int u : g[x])if(u!=fat)dfs2(u, x), pre[u] = x;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1);
	dfs2(be);
	int mx=0, id;
	for(int i=1;i<=n;i++)
		if(dep[i] > mx)mx = dep[i], id = i;
	while(id != be){
		dia[id] = 1;
		di.pb(id);
		id = pre[id];
	}
	dia[be] = 1;
	di.pb(be);
	reverse(di.begin(), di.end());
	
	int cnt = 0;
	for(int now : di){
		for(int u : g[now])
			if(!dia[u])
				leaf[now].pb(u), ++ cnt;
	}
	if(cnt + di.size() != n)
		return puts("No"), 0;
	
	puts("Yes");
	
	vector<int>ans;
	for(int i=0;i<di.size();i+=2){
		int now = di[i];
		ans.pb(now);
		if(i+1 >= di.size())continue;
		for(auto it : leaf[di[i+1]])
			ans.pb(it);
	}
	
	int up = di.size()-1;
	if(up%2 == 0){
		for(auto it : leaf[di[di.size()-1]])
			ans.pb(it);
		-- up;
	}
	for(int i=up;i>=0;i-=2){
		int now = di[i];
		ans.pb(now);
		if(i-1 < 0)continue;
		for(auto it : leaf[di[i-1]])
			ans.pb(it);
	}
	
	for(int it : ans)printf("%d ",it);
	puts("");

	return 0;
}

