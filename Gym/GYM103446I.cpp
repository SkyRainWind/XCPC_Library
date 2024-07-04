// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, big=1500;
ll INF = -0x3f3f3f3f3f3f3f3f;

ll dp[105][105][3005];
int n,k,v[105],t[105];

void go(ll &a,ll b,int c){
	if(b==INF)return ;
	a = max(a, b+c);
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&v[i],&t[i]);
	memset(dp,-0x3f,sizeof dp);
	printf("%lld %lld\n",dp[0][0][0],INF);
	
	dp[0][0][big] = 0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int p=0;p<=3000;p++){
				if(p>=t[i])go(dp[i][j][p], dp[i-1][j][p-t[i]], v[i]);
				if(p+t[i]<=3000)go(dp[i][j][p], dp[i-1][j][p+t[i]], v[i]);
				go(dp[i][j][p], dp[i-1][j][p], 0);
				if(p>=2*t[i]&&j)go(dp[i][j][p], dp[i-1][j-1][p-2*t[i]], v[i]);
				if(p+2*t[i]<=3000&&j)go(dp[i][j][p], dp[i-1][j-1][p+2*t[i]], v[i]);
			}
	
	ll ans = 0;
	for(int i=0;i<=k;i++)
		ans = max(ans, dp[n][i][big]);
	printf("%lld\n",ans);

	return 0;
}

