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

const int inf = 1e9,maxn=355;

int n,m;
int a[maxn],b[maxn],cnt[11];
int dp[41][41][41][41]; 

inline int gt(int i,int j,int k,int u){return i+2*j+3*k+4*u+1;}
void ck(int &a,int b){a=max(a,b);}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),++ cnt[b[i]];
	for(int i=0;i<=cnt[1];i++)for(int j=0;j<=cnt[2];j++)
		for(int k=0;k<=cnt[3];k++)for(int u=0;u<=cnt[4];u++)dp[i][j][k][u]=-1e9;
	dp[0][0][0][0] = a[1];
	for(int tot = 1;tot<=m;tot++){
		for(int i=0;i<=tot&&i<=cnt[1];i++){
			for(int j=0;i+j<=tot&&j<=cnt[2];j++){
				for(int k=0;i+j+k<=tot&&k<=cnt[3];k++){
					int u = tot-i-j-k;
					if(u>cnt[4])continue;
					if(i&&dp[i-1][j][k][u]!=-1e9)ck(dp[i][j][k][u],dp[i-1][j][k][u]+a[gt(i,j,k,u)]);
					if(j&&dp[i][j-1][k][u]!=-1e9)ck(dp[i][j][k][u],dp[i][j-1][k][u]+a[gt(i,j,k,u)]);
					if(k&&dp[i][j][k-1][u]!=-1e9)ck(dp[i][j][k][u],dp[i][j][k-1][u]+a[gt(i,j,k,u)]);
					if(u&&dp[i][j][k][u-1]!=-1e9)ck(dp[i][j][k][u],dp[i][j][k][u-1]+a[gt(i,j,k,u)]);
				}
			}
		}
	}
	printf("%d\n",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);

	return 0;
}


