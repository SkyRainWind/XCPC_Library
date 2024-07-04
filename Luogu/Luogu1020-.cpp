// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 100005;

int a[maxn], n;
int dp[maxn];

signed main(){
//	freopen("1020_.in","r",stdin);
	while(scanf("%lld",&a[++n]) != EOF);
	-- n;
	int ln = 1;
	dp[1] = a[1];
	for(int i=2;i<=n;i++){
		if(dp[ln] >= a[i]){dp[++ ln] = a[i];continue;}
		int cur = upper_bound(dp+1,dp+ln+1,a[i],greater<int>()) - dp;
		dp[cur] = a[i];
	}
	printf("%lld\n",ln);
	memset(dp, 0, sizeof dp);ln = 1;
	dp[1] = a[1]; 
	for(int i=2;i<=n;i++){
		if(dp[ln] < a[i]){dp[++ ln] = a[i];continue;}
		int cur = upper_bound(dp+1,dp+ln+1,a[i]) - dp;
		if(cur == ln + 1)continue;
		if(dp[cur-1] == a[i])continue;
//		printf("%d %d ",dp[cur],ln);
		dp[cur] = a[i];
//		printf("%d %d %d %d %d %d %d\n",cur,i,dp[cur],dp[3],dp[4],dp[5],dp[6]);
	}
	printf("%lld\n",ln);

	return 0;
}


