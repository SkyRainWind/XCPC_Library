// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,mod;
int dp[505][505],C[505][505], p2[505], p22[505];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	scanf("%d%d",&n,&mod);
	C[0][0] = 1;
	for(int i=1;i<=500;i++){
		C[i][0] = 1;
		for(int j=1;j<=500;j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	
	p2[0] = 1;
	for(int i=1;i<=500;i++)p2[i] = 2ll*p2[i-1]%mod;
	for(int i=1;i<=500;i++)p22[i] = pw(2, i*(i-1)/2);
	
	dp[1][1] = 1;
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=i;j++)if(dp[i][j]){
			int coef = 1;
			for(int k=1;i+k<=n-1;k++){
				coef = 1ll*coef*(p2[j]-1)%mod;
				(dp[i+k][k] += 1ll*dp[i][j]*C[n-1-i][k]%mod*p22[k]%mod*coef%mod) %= mod;
			}
		}
	}
	
	int ans = 0;
	for(int i=1;i<=n-1;i++)
		(ans += 1ll*dp[n-1][i]*(p2[i]-1)%mod) %= mod;
	printf("%d\n",ans);

	return 0;
}

