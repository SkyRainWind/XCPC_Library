// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 505;

int n;
struct gauss{
	const double eps = 1e-7;
	double ans[maxn];
	double a[maxn][maxn];
	
	int main(){
		for(int i=1;i<=n;i++){
			int r=i;
			for(int j=i+1;j<=n;j++)if(fabs(a[r][i])<fabs(a[j][i]))r=j;
			if(fabs(a[r][i])<eps){
				return 0;
			}
			
			if(r!=i)swap(a[r],a[i]);
			double div=a[i][i];
			
			for(int j=i;j<=n+1;j++)a[i][j]/=div;
			for(int j=i+1;j<=n;j++){
				div=a[j][i];
				for(int k=i;k<=n+1;k++)a[j][k]-=a[i][k]*div;
			}
		}	
		
		ans[n]=a[n][n+1];
		for(int i=n-1;i>=1;i--){
			ans[i]=a[i][n+1];
			for(int j=i+1;j<=n;j++)ans[i]-=(a[i][j]*ans[j]);
		}
		return 1;
	}
};

signed main(){
	gauss gs;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)scanf("%lf",&gs.a[i][j]);
	int st = gs.main();
	if(!st)puts("No Solution");
	else
		for(int i=1;i<=n;i++)printf("%.2f\n",gs.ans[i]); 

	return 0;
}

