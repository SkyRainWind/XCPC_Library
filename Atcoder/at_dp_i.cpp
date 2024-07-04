// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=3005;

int n;
double p[maxn],dp[maxn][maxn];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	dp[0][0] = 1.0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			dp[i][j] += dp[i-1][j] * (1-p[i]);
		}
		for(int j=1;j<=i;j++){
			dp[i][j] += dp[i-1][j-1] * p[i];
		}
	}
	double res=0.0;
	for(int i=n/2+1;i<=n;i++)res+=dp[n][i];
	printf("%.10f\n",res);

	return 0;
}

