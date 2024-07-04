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

int m,s,t;
int dp[2][1105];
// dp[i][j] 第i秒，j魔力值 走的最远距离 
void ckmx(int &a,int b){a=max(a,b);}

signed main(){
//	freopen("P1095_7.in","r",stdin);
	scanf("%d%d%d",&m,&s,&t);
	memset(dp,-1,sizeof dp);
	int mg = m/10;m%=10;
	if(s-mg*60<=0){
		printf("Yes\n%d\n",(s-1)/60+1);
		return 0;
	}
	s -= mg*60;
	t -= mg;
	if(t <= 0){
		printf("No\n%d\n",(t+mg)*60);
		return 0;
	}
	
	dp[0][m] = 0;
	int ans=0;
	for(int i=1;i<=t;i++)
		for(int j=0;j<=20;j++){
			if(dp[(i%2)^1][j]!=-1)dp[i%2][j] = dp[(i%2)^1][j] + 17;
			if(j>=4&&dp[(i%2)^1][j-4]!=-1)ckmx(dp[i%2][j],dp[(i%2)^1][j-4]);
			if(j<=10&&dp[(i%2)^1][j+10]!=-1)ckmx(dp[i%2][j],dp[(i%2)^1][j+10]+60);
			if(dp[i%2][j] >= s)return printf("Yes\n%d\n",i+mg),0;
			ckmx(ans,dp[i%2][j]);
		}
	printf("No\n%d\n",ans+mg*60);

	return 0;
}


