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

const int inf = 1e9,maxn=3005;

int dp[3005][3005][3];
char sa[maxn],sb[maxn];
int d[6][6];
int A,B;
int n,m;

int conv(char ss){if(ss=='A')return 1;if(ss=='T')return 2;if(ss=='G')return 3;return 4;}
int dd(char ca,char cb){
	int ta=conv(ca),tb=conv(cb);
	return d[ta][tb];
}
void ck(int &a,int b,int c){if(b!=-1e9)a=max(a,b+c);}
int isA(int k){if(k==1)return -A+B;return 0;}

signed main(){
	scanf("%s",sa+1);scanf("%s",sb+1);
	for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)scanf("%d",&d[i][j]);
	scanf("%d%d",&A,&B);
	n=strlen(sa+1),m=strlen(sb+1);
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)for(int k=0;k<=2;k++)
		dp[i][j][k] = dp[i][j][k] = -1e9;
		 
	dp[0][0][0] = 0;
	
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){
		if(j){
			ck(dp[i][j][1],dp[i][j-1][1],-B);
			ck(dp[i][j][1],dp[i][j-1][2],-A);
			ck(dp[i][j][1],dp[i][j-1][0],-A);
		}
		if(i){
			ck(dp[i][j][2],dp[i-1][j][2],-B);
			ck(dp[i][j][2],dp[i-1][j][1],-A);
			ck(dp[i][j][2],dp[i-1][j][0],-A);
		}
		if(i&&j){
			ck(dp[i][j][0], dp[i-1][j-1][0],dd(sa[i],sb[j]));
			ck(dp[i][j][0], dp[i-1][j-1][1],dd(sa[i],sb[j]));
			ck(dp[i][j][0], dp[i-1][j-1][2],dd(sa[i],sb[j]));
		}
	}
	int ans=-1e9;//-1e9 ²»ÊÇ0 !!! 
	for(int k=0;k<=2;k++)ck(ans,dp[n][m][k], 0);
	printf("%d\n",ans);

	return 0;
}


