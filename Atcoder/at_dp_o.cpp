// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=23, mod=1e9+7;

int n,a[maxn][maxn];
int b[25][25],cnt[222];

int dp[22][(1<<21)+5];
int dfs(int x, int S){
	if(x==n+1)return 1;
	int &ddd = dp[x][S];
	if(~ddd)return ddd;
	
	int dd=0;
	for(int i=1;i<=cnt[x];i++){int it=b[x][i];if((S & (1<<(it-1)))==0){
		(dd += dfs(x+1, S ^ (1<<(it-1))));
		if(dd >= mod)dd -= mod;
	}}
	return ddd=dd;
}

signed main(){
	memset(dp,-1,sizeof dp); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j])b[i][++cnt[i]]=j;
		}
	ll res = dfs(1, 0);
	cout<<res;

	return 0;
}

