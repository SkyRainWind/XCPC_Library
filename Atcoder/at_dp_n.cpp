// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=405;
int n,a[maxn];
ll dp[maxn][maxn],sum[maxn];
signed main(){
	memset(dp,0x3f,sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), dp[i][i] = 0, sum[i] = sum[i-1]+a[i];
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j = i+l-1;
			ll ndp = 1e18;
			for(int k=i;k<j;k++){
				ndp = min(ndp, dp[i][k] + dp[k+1][j]);
			}
			dp[i][j] = ndp + sum[j] - sum[i-1];
		}
	}
	cout<<dp[1][n];

	return 0;
}

