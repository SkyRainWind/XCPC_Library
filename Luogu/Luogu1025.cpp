// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
int n,k;
ll dp[205][205];
signed main(){
	scanf("%d%d",&n,&k);
	dp[0][0] = 1;
	for(int t=1;t<=n;t++)
		for(int i=t;i<=n;i++)
			for(int j=1;j<=k;j++)
				dp[i][j] += dp[i-t][j-1];
	cout<<dp[n][k];

	return 0;
}

