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

int n,a[maxn],sum[maxn];
int dp[maxn][maxn],f[maxn][maxn];
// dp[i][j] [i..j]合并的最小代价 
// dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]

void ck(int &a,int b,int c){a=max(a,b+c);}
void ck2(int &a,int b,int c){a=min(a,b+c);}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);a[i+n]=a[i];}
	for(int i=1;i<=2*n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=2*n;i++){for(int j=i;j<=2*n;j++)f[i][j]=1e9;f[i][i]=0;}
	for(int l=1;l<=n;l++){
		for(int i=1;i+l<=2*n;i++){
			int j = i+l;
			for(int k=i;k<=j-1;k++){
				ck(dp[i][j], dp[i][k]+dp[k+1][j],sum[j]-sum[i-1]);
				ck2(f[i][j],f[i][k]+f[k+1][j],sum[j]-sum[i-1]);
			}
		}
	}
	int ans0=1e9;for(int i=1;i<=n;i++)ans0=min(ans0,f[i][i+n-1]);printf("%d\n",ans0);
	int ans1=0;for(int i=1;i<=n;i++)ans1=max(ans1,dp[i][i+n-1]);printf("%d\n",ans1);

	return 0;
}


