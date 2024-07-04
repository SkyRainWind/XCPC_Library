// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,b[5];
double dp[302][302][302];

signed main(){
	int r=0;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),++b[x],r+=x;
	for(int tn=1;tn<=r;tn++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				int k=tn-i-2*j;
				if(k%3)continue;
				k /= 3;
				if(k < 0 || k > n)continue;
				if(i)dp[i][j][k] += 1.0 * dp[i-1][j][k] * i/(i+j+k);
				if(j)dp[i][j][k] += 1.0*dp[i+1][j-1][k] * j/(i+j+k);
				if(k)dp[i][j][k] += 1.0*dp[i][j+1][k-1] * k/(i+j+k);
				dp[i][j][k] += 1.0 * n / (i+j+k);
			}
		}
	}
	printf("%.15f\n",dp[b[1]][b[2]][b[3]]);

	return 0;
}

