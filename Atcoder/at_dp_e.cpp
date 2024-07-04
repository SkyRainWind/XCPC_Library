// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=105;

int n,W,w[maxn],v[maxn];
int dp[105][100005];
signed main(){
	memset(dp, 0x3f, sizeof dp);
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&v[i]);
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j+v[i]<=100000;j++){
			dp[i][j + v[i]] = min(dp[i][j + v[i]], dp[i-1][j] + w[i]);
		}
		for(int j=0;j<=100000;j++)dp[i][j] = min(dp[i][j], dp[i-1][j]);
	}
	for(int i=100000;i>=0;i--)
		if(dp[n][i]<=W)return printf("%d\n",i),0;

	return 0;
}

