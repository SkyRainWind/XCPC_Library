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

int n,m;
double dp[5005][5005];

signed main(){
	scanf("%d%d",&n,&m);
	double p = n/m+1;p /= n;
	double q = n/m;q /= n;
	int nump = n%m, numq = m - n%m;
	// cout << nump << ' ' << numq << '\n';

	dp[0][0] = 0;
	for(int i=0;i<=nump;i++)
		for(int j=0;j<=numq;j++)if(i+j){
			double bs = p*i + q*j;
			// printf("? %f %f %f\n",bs,p,q);
			dp[i][j] = (i ? p*i / bs * dp[i-1][j] : 0) + 
				(j ? q*j / bs * dp[i][j-1] : 0) + 1. / bs;
		}
	printf("%.8f\n",dp[nump][numq]);

	return 0;
}
