// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n,a[maxn];
vector<int>g[maxn];
int sz[maxn], heavy[maxn];

void dfs0(int x,int fat=0){
	sz[x] = 1;
	for(int u : g[x])if(u != fat){
		dfs0(u, x);
		sz[x] += sz[u];
		if(!heavy[x] || sz[heavy[x]] < sz[u])
			heavy[x] = u;
	}
}

int t[maxn],K[maxn],f[maxn];
map<int,bool>M[maxn];
void dfs(int x,int fat=0){
	if(fat && g[x].size() == 1){
		t[x] = x;
		M[t[x]][0] = 0;
		K[x] = a[x];
		return ;
	}
	
	map<int,int>S;
	dfs(heavy[x], x);
	t[x] = t[heavy[x]];
	K[x] = K[heavy[x]];
	int c=1, sum = f[heavy[x]], w=1;
	
	for(auto &u : g[x])if(u != fat && u != heavy[x]){
		dfs(u, x);
		for(auto &v : M[t[u]])
			S[v.first ^ K[u]] ++;
		++ c;
		sum += f[u];
	}
	for(auto &u : S){
		if(M[t[x]].count(u.first ^ K[x]))++ u.second;
		w = max(w, u.second);
	}
	if(w == 1){
		for(auto &u : S)
			M[t[x]][u.first ^ K[x]] = 1;
	}else{
		M[t[x]].clear();
		for(auto &u : S)
			if(u.second == w)
				M[t[x]][u.first ^ K[x]] = 1;
	}
	K[x] ^= a[x];
	f[x] = sum + c - w;
}

int qread(){
    int w = 1, c, ret;
    while((c = getchar()) >  '9' || c <  '0') w = (c == '-' ? -1 : 1); ret = c - '0';
    while((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + c - '0';
    return ret * w;
}

signed main(){
	n=qread();
	for(int i=1;i<=n;i++)a[i]=qread();
	for(int i=1;i<n;i++){
		int x=qread(),y=qread();
		g[x].pb(y), g[y].pb(x);
	}
	dfs0(1);
	dfs(1);
	for(auto &u : M[t[1]])
		if((u.first ^ K[1]) == 0){
			return printf("%d\n",f[1]), 0;
		}
	printf("%d\n",f[1] + 1);

	return 0;
}

