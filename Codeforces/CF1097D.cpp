// by Balloons
#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,mod=1e9+7,N=3.2e7;

LL n;
int k,cnt=0;

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int notpm[N+5],pm[2000005],pcnt=0;

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=N;i++){
		if(!notpm[i]){
			pm[++ pcnt]=i;
		}
		for(int j=1;j<=pcnt && i*pm[j] <= N;j++){
			notpm[pm[j] * i] = 1;
			if(i%pm[j] == 0)break;
		}
	}
}

int inv[N+5];
int dp[2][65];
int solve(int x,int cs){
	memset(dp,0,sizeof dp);
	dp[0][cs] = 1;
	for(int i=1;i<=k;i++){
		memset(dp[i&1],0,sizeof dp[i&1]);
		for(int j=0;j<=cs;j++){
			int ret=0;
			for(int kk=j;kk<=cs;kk++){
				(ret += 1ll*dp[i&1^1][kk] * inv[kk+1]%mod)%=mod;
			}
			dp[i&1][j] = ret;
		}
	}
	int res = 0;
	int bs=1;
	for(int i=0;i<=cs;i++,bs=1ll*bs*(x%mod)%mod)(res += 1ll*dp[k&1][i]*bs%mod) %= mod;
	return res;
}

signed main(){
	scanf("%I64d%d",&n,&k);
	xxs();
	inv[1] = 1;
	for(int i=2;i<=N;i++){
		inv[i] = 1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	LL qwq = n,ans=1;
	for(int i=1;i<=pcnt;i++){
		if(qwq%pm[i]==0){
			int cs=0;
			while(qwq%pm[i]==0)qwq /= pm[i],cs ++;
			ans = 1ll*ans*solve(pm[i],cs)%mod; 
		}
	}
	if(qwq != 1)ans = 1ll*ans*solve(qwq%mod, 1)% mod;
	printf("%I64d\n",ans);
	
	return 0;
}


