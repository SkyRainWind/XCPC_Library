// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e6+5;

int n;
int ch[maxn][28],sz[maxn];
vector<pair<int,char>>g[maxn];

void dfs(int x,int fat=0){
	sz[x] = 1;
	for(auto it : g[x])if(it.first != fat)dfs(it.first, x), sz[x] += sz[it.first];
}

int dt=0;
void dfs2(int x,int fat){
	for(int j=0;j<26;j++)if(ch[x][j] == 2)++ dt;
	for(auto it : g[x])if(it.first != fat){
		dfs2(it.first, x);
	}
}

int ff=0, go;
int dfs0(int x,int fat=0){
	int have = 0;
	for(auto u : g[x])if(u.first!=fat){
		have += dfs0(u.first, x);
	}
	if(have >= 2){ff = 2;return 1;}
	if(!have)
		for(int j=0;j<26;j++)if(ch[x][j] == 2){go=x;if(ff!=2)ff=1;return 1;}
	return have;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		sz[i] = 0;
		for(int j=0;j<26;j++)ch[i][j] = 0;
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		char c[5];scanf("%s",c+1); 
		ch[x][c[1]-'a']++, ch[y][c[1]-'a']++;
		g[x].pb(mpr(y,c[1])), g[y].pb(mpr(x,c[1]));
	}
	int f=0, go, del=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++){
			if(ch[i][j] >= 3)f = 1;
			if(ch[i][j] == 2)++ del; 
		}
	if(f){
		puts("0");
		return ;
	}
	ff = 0, go = 0;
	dfs0(1);
	cerr<<"FF " <<ff<<'\n'; 
	if(ff == 2){
		puts("0");
		return ;
	}
	
	if(ff == 0){
		printf("%d\n",n - del);
		return ;
	}
//	printf("? %d\n",go);
	dfs(go);
	int ans = 0;
	dt = 0;
	for(auto it : g[go]){
		if(ch[go][it.second-'a'] == 2){
			ans += sz[it.first];
			dfs2(it.first, go);
		}
	}
	printf("%d\n",ans - dt);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

