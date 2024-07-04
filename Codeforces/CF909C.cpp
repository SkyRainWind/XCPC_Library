// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod=1e9+7;
char st[5005][3];
int n,dp[5005][5005],to[5005];
signed main(){
	int m = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",st[i]+1), st[i][1] == 'f' ? ++m : 1;
	dp[1][0] = 1;
	for(int i=2;i<=n;i++){
		if(st[i-1][1] == 'f')
			for(int j=1;j<=m;j++)
				dp[i][j] = dp[i-1][j-1];
		else{
			int s = 0;
			int sum[5005];sum[m+1] = 0;
			for(int j=m;j>=0;j--)sum[j] = (sum[j+1] + dp[i-1][j])%mod;
			for(int j=0;j<=m;j++){
				dp[i][j] = sum[j];
			}
		}
	}	
	int ans = 0;
	for(int j=0;j<=m;j++)(ans += dp[n][j]) %= mod;
	printf("%d\n",ans);

	return 0;
}
