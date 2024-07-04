// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#include <cmath>
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1 << 30;

int num[222],len=0;
int dp[33][12];
int a,b;

int solve(int cur=1,int pre0=1,int less=1,int lastnum=-1){
	if(cur==len+1)return 1;
	if(pre0!=1 && less==0 && dp[cur][lastnum]!=-1)return dp[cur][lastnum];
	
	int ret=0,en=less?num[cur]:9;
	for(int i=0;i<=en;i++){
		if(pre0||(!pre0&&abs(lastnum-i)>=2)){
			ret+=solve(cur+1,pre0&&i==0,less&&i==en,(pre0&&i==0)?lastnum:i);
		}	
	}
	if(lastnum>=0&&less==0)dp[cur][lastnum]=ret;
	return ret;
}

int getans(int x){
	len=0;
	int tx=x;
	while(tx){
		num[++len]=tx%10;tx/=10;
	}
	memset(dp,-1,sizeof dp);
	reverse(num+1,num+len+1);
	return solve();
}

signed main(){
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",getans(b)-getans(a-1));

	return 0;
}
