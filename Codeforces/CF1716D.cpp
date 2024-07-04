// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int dp[2][200005];
int pre[200005],ans[200005];
int n,k;

signed main(){
	scanf("%d%d",&n,&k);
	int m;
	int curst = 0;for(int i=1;;i++){curst += k+i-1;if(curst >= n){m = i;break;}}
	dp[0][0] = 1;
	for(int i=1;i<=m;i++){
		memset(pre,0,sizeof pre);
		memset(dp[i&1],0,sizeof dp[i&1]);
		for(int j=0;j<=n;j++)if(j < (k+i-1))pre[j] = dp[i&1^1][j];else pre[j] = (pre[j-(k+i-1)] + dp[i&1^1][j])%998244353;
		for(int j=0;j<=n;j++)if(j >= (k+i-1))dp[i&1][j] = pre[j-(k+i-1)];
		for(int j=1;j<=n;j++)(ans[j] += dp[i&1][j])%=998244353;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");

	return 0;
}


