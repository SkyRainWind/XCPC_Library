// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e4+5;

int n,m;
vector<int>g[maxn],inv[maxn];
int de[maxn];
bitset<maxn>mk[maxn];
int t[maxn],cnt =0;

void topo(){
	queue<int>Q;
	for(int i=1;i<=n;i++){
		if(!de[i]){
			Q.push(i);
			t[++cnt]=i;
		}
	}
	
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(int v : inv[u]){
			if(!--de[v]){
				t[++cnt]=v;
				Q.push(v);
			}
		}
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y);
		inv[y].pb(x);
		++ de[x];
	}
	
	topo();
	for(int i=1;i<=n;i++){
		int u = t[i];
		mk[u][u] = 1;
		for(int v : inv[u])mk[v] |= mk[u];
	}
	for(int i=1;i<=n;i++)printf("%d\n",mk[i].count());

	return 0;
}

