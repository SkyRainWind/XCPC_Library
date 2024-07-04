// by Balloons
#include <cstdio>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,mod=998244353;

int n;
int pw(int x,int y){
	if(!y)return 1;if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}
int dp[200005];
int cnt,a[20005];
set<int>S;
void dfs(int l,int r){
	if(l == r+1){
		if((cnt&1)){
			int x = 0;
			for(int i=1;i<=cnt;i++)x ^= a[i];
			S.insert(x);
		}
		return ;
	}
	dfs(l+1,r);
	a[++ cnt]=l;
	dfs(l+1,r);
	-- cnt;
}
signed main(){
//	dfs(0,16);
//	printf("%d\n",S.size());	// N = 3, ans = 2^3; N = 4, ans = 2^4
//	return 0;
	scanf("%d",&n);
	dp[0] = 1;
	dp[1] = pw(2,n)%mod;
	LL ans = (dp[0]+dp[1])%mod;
	for(int i=2;i<=n+2;i++){
		dp[i] = 1ll*dp[i-1]*((pw(2,n) - pw(2,i-2)+mod)%mod)%mod*pw(i,mod-2)%mod;
		ans = (ans+dp[i])%mod;
	}
	printf("%d\n",ans);

	return 0;
}


