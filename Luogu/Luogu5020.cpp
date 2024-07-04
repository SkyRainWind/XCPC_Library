// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n;
int dp[25005],a[105];

void solve(){
	memset(dp,0,sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(dp[a[i]])continue;
		++ ans;
		dp[a[i]] = 1;
		for(int j=1;a[i]+j<=25000;j++)dp[a[i] + j] |= dp[j];
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


