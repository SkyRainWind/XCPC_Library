// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, maxn=25;
const double eps = 1e-6;

int n;
double x[maxn],y[maxn];
int line[maxn][maxn];
int dp[(1<<18)+5];

void get(double &a,double &b,double x1,double y1,double x2,double y2){
	if(x1 == x2){a=1;return ;}
	b = (y1*x2*x2/x1/x1 - y2) / (x2*x2/x1 - x2);
	a = y1-b*x1;a /= (x1*x1);
}

void solve(){
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&x[i],&y[i]);
	}
	memset(line,-1,sizeof line); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(i!=j){
			double a,b;
			get(a,b,x[i],y[i],x[j],y[j]);
			if(a>=-eps)continue;	//!!!
			line[i][j] = (1<<(i-1)) | ((1<<(j-1)));
			for(int k=1;k<=n;k++)if(i!=j&&i!=k){
				if(fabs(a*x[k]*x[k]+b*x[k]-y[k]) <= eps){
					line[i][j] |= (1<<(k-1));
				}
			}
		}
	}
	
	for(int S=0;S<=(1<<n)-1;S++)dp[S] = inf;
	dp[0] = 0;
	for(int S=0;S<=(1<<n)-1;S++){
		for(int i=1;i<=n;i++)if((S&(1<<(i-1)))==0){
			for(int j=1;j<=n;j++)if(i!=j && (S&(1<<(j-1)))==0){
				if(line[i][j]==-1)continue;
				dp[S|line[i][j]] = min(dp[S|line[i][j]], dp[S]+1);
			}
		}
		for(int i=1;i<=n;i++)if((S&(1<<(i-1)))==0)
			dp[S|(1<<(i-1))] = min(dp[S|(1<<(i-1))], dp[S]+1);
	}
	printf("%d\n",dp[(1<<n)-1]);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


