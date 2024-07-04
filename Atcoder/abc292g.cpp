// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353;

int n,m;
char s[45][45];
int dp[45][45][45][13];

int dfs(int l,int r,int p,int c){
	int &dd = dp[l][r][p][c];
	if(~dd)return dd;
	if(p == m+1)return dd = (l == r);
	if(c >= 10)return dd = 0;
	
	dd = dfs(l,r,p,c+1);
//		printf("!! %d %d %d %d %d\n",l,r,p,c,dd);
	int gg = 0;
	for(int k=l;k<=r;k++){
		if(s[k][p] == '?' || s[k][p] - '0' == c){
			if(k == r)(dd += dfs(l,r,p+1,0)) %= mod;
			else (dd += 1ll*dfs(l,k,p+1,0)*dfs(k+1,r,p,c+1)%mod) %= mod;
		}
		else{gg = 1;break;}
	}
//	printf("! %d %d %d %d %d\n",l,r,p,c,dd);
	return dd;
}

signed main(){
	memset(dp,-1,sizeof dp);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	int res = dfs(1,n,1,0);
	printf("%d\n",res);

	return 0;
}

