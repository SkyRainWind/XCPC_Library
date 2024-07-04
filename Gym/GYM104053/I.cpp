// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2000+5,mod=1e9+7;

int n;
vector<int>gr[maxn];
int a[maxn],p[maxn];
int f[maxn][maxn],g[maxn][maxn];

int pw(int x,int y){
	if(y==0)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}
int ans[maxn],t1[maxn],t2[maxn],sz[maxn];

void dfs(int x,int fat=0){
	f[x][0] = (mod+1-p[x])%mod;
	f[x][1] = p[x], g[x][1] = a[x];
	sz[x] = 1;
	for(int u : gr[x])if(u!=fat){
		dfs(u, x);
		for(int i=0;i<=sz[x]+sz[u];i++)t1[i] = t2[i] = 0;
		for(int j=1;j<=sz[x];j++)
			for(int k=0;k<=sz[u];k++){
				(t1[j+k] += 1ll*f[x][j]*f[u][k]%mod) %= mod;
				(t2[j+k] += 1ll*g[x][j]*f[u][k]%mod) %= mod;
				if(k)(t2[j+k] += 1ll*f[x][j]*g[u][k]%mod) %= mod;
			}
		for(int j=1;j<=sz[x]+sz[u];j++)f[x][j] = t1[j], g[x][j] = t2[j];
		sz[x] += sz[u];
	}
	for(int i=1;i<=sz[x];i++)
		(ans[i] += 1ll*g[x][i]*(mod+1-p[fat])%mod) %= mod;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){int x,y;scanf("%d%d",&x,&y);gr[x].pb(y),gr[y].pb(x);}
	int sum=0;
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d%d",&a[i],&x,&y);
		x = 1ll*x*pw(y,mod-2)%mod;
		p[i] = x;
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)a[i] = 1ll*a[i]*pw(sum,mod-2)%mod;
	dfs(1);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);

	return 0;
}

