// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=205;

int n,a[maxn*2];
int dp[maxn][maxn];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i+n]=a[i+2*n]=a[i],dp[i][i]=dp[i+n][i+n]=0;
	for(int i=1;i<=2*n;i++)for(int j=i+1;j<=2*n;j++)dp[i][j] = -1e9;
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=2*n;i++){
			int j=i+l-1;
			for(int k=i;k+1<=j;k++){
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		}
	int ans=-1e9;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i][i+n-1]);
	printf("%d\n",ans);

	return 0;
}


