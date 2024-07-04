// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m;
int dp[52][52][52][52];
int a[52][52];

int notc(int x,int y,int x0,int y0){
//	printf("?? %d %d %d %d %d\n",x,y,x0,y0,(x==x0&&y==y0&&x==n&&y==m) || ((!(x==x0&&y==y0)) && x<=n&&x0<=n&&y<=m&&y0<=m));
	return (x==x0&&y==y0&&x==n&&y==m) || ((!(x==x0&&y==y0)) && x<=n&&x0<=n&&y<=m&&y0<=m);
}
void ckmx(int &a,int b){a = max(a, b);}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
//	printf("%d\n",notc(1,2,2,1));
	dp[1][1][1][1] = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=n;k++)
				for(int l=1;l<=m;l++){
//					printf("%d %d %d %d\n",i,j,k,l);
					if(((i+j+k+l == 4) || (!(i==k&&j==l))) && (i+j == k+l)){
						if(notc(i+1,j,k+1,l))ckmx(dp[i+1][j][k+1][l], dp[i][j][k][l] + a[i+1][j] + a[k+1][l]);
						if(notc(i,j+1,k+1,l))ckmx(dp[i][j+1][k+1][l], dp[i][j][k][l] + a[i][j+1] + a[k+1][l]);
						if(notc(i+1,j,k,l+1))ckmx(dp[i+1][j][k][l+1], dp[i][j][k][l] + a[i+1][j] + a[k][l+1]);
						if(notc(i,j+1,k,l+1))ckmx(dp[i][j+1][k][l+1], dp[i][j][k][l] + a[i][j+1] + a[k][l+1]);
					}
				}
	printf("%d\n",dp[n][m][n][m]);

	return 0;
}


