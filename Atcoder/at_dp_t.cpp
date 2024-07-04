// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3005, mod = 1e9+7;

ll dp[3005][3005];
int n;
char s[3005];
ll sum[3005];

signed main(){
	scanf("%d",&n);scanf("%s",s + 2);
	dp[1][1] = sum[1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(s[i] == '<')dp[i][j] = sum[j-1];
			else dp[i][j] = sum[i-1] - sum[j-1] + mod, dp[i][j] %= mod;
		}
		for(int j=1;j<=i;j++)sum[j] = sum[j-1] + dp[i][j], sum[j] %= mod;
	}
	ll ans = 0;
	for(int i=1;i<=n;i++)(ans += dp[n][i]) %= mod;
	cout << ans;

	return 0;
}

