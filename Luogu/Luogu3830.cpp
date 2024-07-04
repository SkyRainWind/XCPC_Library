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

double dp[105][105],pre[105][105];

signed main(){
	int q,n;scanf("%d%d",&q,&n);
	if(q == 1){
		vector<double>f(n+1, 0.0);
		f[1] = 0;
		for(int i=2;i<=n;i++){
			f[i] = 1.0*i/(i-1)*f[i-1] + 2.0;
		}
		printf("%.6f\n",f[n] / n);
	}else{
		dp[1][0] = 1.0;
		for(int i=0;i<=n;i++)pre[1][i] = 1.0;
//		for(int i=2;i<=n;i++){
//			for(int j=1;j<=i-1;j++){
//				for(int L=1;L<i;L++){
//					double r=0.0;
//					for(int x=0;x<j;x++)
//						for(int y=0;y<j;y++)if(x==j-1 || y==j-1)
//							r += dp[i-L][x] * dp[L][y];
//					dp[i][j] += 1.0 / (i-1) * r;
//				}
//			}
//		}

		for(int i=2;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				for(int L=1;L<i;L++){
					double r=0.0;
					r = pre[i-L][j-1] * dp[L][j-1] + dp[i-L][j-1] * pre[L][j-1] - dp[i-L][j-1] * dp[L][j-1];
					dp[i][j] += 1.0 / (i-1) * r;
				}
			}
			for(int j=1;j<=n;j++)pre[i][j] = pre[i][j-1] + dp[i][j];
		}
		double ans=0.0;
		for(int i=1;i<=n;i++)
			ans += 1.0 * i * dp[n][i];
		printf("%.6f\n",ans); 
	}

	return 0;
}

