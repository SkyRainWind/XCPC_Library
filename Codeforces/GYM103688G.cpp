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

int n,c[2005];
int dp[2005][2005];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2000;j++)dp[i][j] = dp[i-1][j];
		if(c[i])
			for(int j=c[i];j<=2000;j++)
				(dp[i][j] += dp[i-1][j - c[i]]) %= mod;
	}
	for(int i=n;i>=1;i--)
		if(dp[n][i]){
			printf("%d %d\n",i,dp[n][i]);
			return 0;
		}

	return 0;
}

