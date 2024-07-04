// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353;

ll n;
int t1,t2,t3;
int dp[64][64][64];

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

void upd(int &x,int y){
	(x+=y)%=mod;
}

signed main(){
	scanf("%lld",&n);
	while(n%2==0){n/=2;++t1;}
	while(n%3==0){n/=3;++t2;}
	while(n%5==0){n/=5;++t3;}
	if(n != 1)return puts("0"), 0;
	int iv=pw(5,mod-2);
	dp[0][0][0] = 1;
	for(int i=0;i<=t1;i++)
		for(int j=0;j<=t2;j++)
			for(int k=0;k<=t3;k++){
				if(i >= 1)upd(dp[i][j][k], 1ll*dp[i-1][j][k]*iv%mod);
				if(j >= 1)upd(dp[i][j][k], 1ll*dp[i][j-1][k]*iv%mod);
				if(k >= 1)upd(dp[i][j][k], 1ll*dp[i][j][k-1]*iv%mod);
				if(i >= 2)upd(dp[i][j][k], 1ll*dp[i-2][j][k]*iv%mod);
				if(i >= 1 && j >= 1)upd(dp[i][j][k], 1ll*dp[i-1][j-1][k]*iv%mod);
			}
	printf("%d\n",dp[t1][t2][t3]);

	return 0;
}

