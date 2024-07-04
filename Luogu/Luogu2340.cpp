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

const int inf = 1e9;

int n;
int s[810005],f[810005];
int dp[2][810005];
void ck(int &a,int b,int c){if(b!=-1e9)a=max(a,b+c);}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i],&f[i]);
		s[i];
	}
	int bs = 1000*n; 
	for(int i=0;i<=810000;i++)dp[0][i]=dp[1][i]=-1e9;
	dp[0][bs]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=bs*2;j++){
			dp[i&1][j] = dp[i&1^1][j];
			if(j>=s[i])ck(dp[i&1][j], dp[i&1^1][j-s[i]] , f[i]);
		}
	}
//	printf("%d\n",dp[n&1][-5+bs]);
	int ans=-1e9;
	for(int i=bs;i<=bs*2;i++)
		if(dp[n&1][i] >= 0)ck(ans,dp[n&1][i],i-bs);
	printf("%d\n",ans);

	return 0;
}


