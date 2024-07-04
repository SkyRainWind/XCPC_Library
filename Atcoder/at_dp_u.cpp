// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 18, maxm = (1<<16) + 5;

int n;
int a[maxn][maxn];
ll cap[maxm], dp[maxm];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int S=0;S<=(1<<n)-1;S++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if((S & (1<<i-1)) && (S & (1<<j-1)))
					cap[S] += a[i][j];
	}
	dp[0] = 0;
	for(int S=1;S<=(1<<n)-1;S++){
		for(int T=S;T;T=(T-1)&S){
			dp[S] = max(dp[S], dp[T] + cap[S ^ T]); 
		}
		dp[S] = max(dp[S], cap[S]);
	}
	cout << dp[(1<<n)-1];

	return 0;
}

