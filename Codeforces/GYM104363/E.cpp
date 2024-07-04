// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

double dp[(1<<11) + 5][12];
int n,m;

signed main(){
	scanf("%d%d",&n,&m);
	if(n == m)
		return printf("%.8f\n",1.0 / n), 0;
	int fm=0;
	for(int S=0;S<(1<<n);S++)
		if(__builtin_popcount(S) == m)++ fm;
	for(int S=0;S<(1<<n);S++)
		if(__builtin_popcount(S) == m)dp[S][m] = 1. / fm;
	for(int i=m+1;i<=n-1;i++)
		for(int S=0;S<(1<<n);S++)
			if(__builtin_popcount(S) == i-1){
				if((S&(1<<(i-1))) == 0){
					dp[S ^ (1<<(i-1))][i] += dp[S][i-1];
				}else{
					for(int j=0;j<n;j++)
						if((S&(1<<j)) == 0){
							dp[S ^ (1<<j)][i] += dp[S][i-1] / (n-i+1);
						}
				}
			}
	printf("%.8f\n",dp[(1<<n-1)-1][n-1]);

	return 0;
}
// xx.. 1/6 .xx. 1/12 x.x.1/12