// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=3005;

int n,a[maxn];
ll dp[maxn][maxn];
signed main(){
//	memset(dp,127,sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), dp[i+1][i] = 0;
	dp[1][0] = 0;
	
	for(int l=1;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			if((n-l+1)&1)dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j]);
			else dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j]);
		}
	}
	cout<<dp[1][n];

	return 0;
}

