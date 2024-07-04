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

const int inf = 1e9,maxn=10005,mod=1e6+7;

int n,m;
int a[maxn];
int ck(int &a,int b){a+=b;a%=mod;}
int dp[105][105];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[0][0] = 1;
//	for(int i=0;i<=n;i++)dp[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++){
			for(int k=0;k<=a[i]&&k<=j;k++){
				ck(dp[i][j],dp[i-1][j-k]);
			}
		}
//	printf("%d\n",dp[2][5]);
	printf("%d\n",dp[n][m]);

	return 0;
}


