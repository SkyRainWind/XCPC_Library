// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 990804011, maxn = 55;

int n;
char s[maxn];
ll dp[maxn][maxn][22][29];
int a[maxn][maxn], ml;

ll dfs(int l,int r,int p,int c){
	ll &dd = dp[l][r][p][c];
	if(~dd)return dd;
	if(c == 27)return dd = 0;
	if(p > ml)return dd = (l == r);
	
	dd = dfs(l, r, p, c+1);
	int gg=0;
	for(int k=l;k<=r-1;k++){
		if((a[k][p] == c) || (a[k][p] == 27 && c))
			(dd += 1ll * dfs(l,k,p+1,0) * dfs(k+1,r,p,c+1)%mod) %= mod;
		else{gg = 1;break;}
	}
	if(!gg && (a[r][p]==c || (a[r][p]==27&&c)))(dd += dfs(l,r,p+1,0)) %= mod;
	return dd;
}

signed main(){
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s + 1);
		int l = strlen(s + 1);
		ml = max(ml, l); 
		for(int j=1;j<=l;j++)
			a[i][j] = s[j] == '?' ? 27 : s[j] - 'a' + 1;
	}
	ll ans = dfs(1, n, 1, 0);
	cout<<ans;

	return 0;
}

