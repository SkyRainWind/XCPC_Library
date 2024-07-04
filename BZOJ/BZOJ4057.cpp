// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,a[25][25];
int dp[(1<<20) + 5];	// dp[S] 表示 S 的状态是否可以到达，S 中 1 代表存活，0 破产 

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=(1<<n)-1;i++)dp[i] = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	dp[(1<<n) - 1] = 1;
	for(int S=(1<<n)-1;S>=1;S--){
		int sum = 0;
		int tmpp[35],tt=0;
		for(int i=1;i<=n;i++)if(S&(1<<i-1))tmpp[++ tt]=i;
		for(int i=1;i<=tt;i++){
			int tmp = 0;
			for(int j=1;j<=tt;j++)if(i!=j){
				tmp += a[tmpp[i]][tmpp[j]];
			}
			if(tmp > 0)dp[S ^ (1<<(tmpp[i]-1))] |= dp[S];
		}
	}
	int ok = 0;
	for(int i=1;i<=n;i++)
		if(dp[(1<<(i-1))]){ok = 1;printf("%d ",i);}
	printf("%c", "0\n"[ok == 1]);
}

signed main(){
//	freopen("BZOJ4057.in","r",stdin);
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


