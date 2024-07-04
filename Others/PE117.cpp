// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
ll dp[222];
ll solve(int x,int bs,int f=0){
	if(x==0)return f;
	if(x<0)return 0;
	if(dp[x])return dp[x];
	return dp[x] = solve(x-bs,bs,1)+solve(x-1,bs,f);
}

signed main(){
	ll r=0;
	for(int i=2;i<=4;i++)memset(dp,0,sizeof dp),r+=solve(50,i);
	printf("%lld\n",r);

	return 0;
}

