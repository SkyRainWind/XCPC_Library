// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,mod=1e9+7,maxn=100005;

int n,k,a[maxn];
int dp[maxn], sum[maxn];
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[0] = sum[0] = 1;
	for(int i=1;i<=k;i++)sum[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=k;j>=1;j--){
			// dp[j] += dp[j-a[i]]+..+dp[j-1]
			(dp[j] += (sum[j-1] - ((j-a[i]-1 < 0) ? 0 : sum[max(0, j-a[i]-1)]) + mod)%mod) %= mod;
		}
//		printf("%d\n",dp[2]);
		for(int j=1;j<=k;j++)sum[j] = sum[j-1] + dp[j], sum[j] %= mod;
	}
	cout<<dp[k];

	return 0;
}

