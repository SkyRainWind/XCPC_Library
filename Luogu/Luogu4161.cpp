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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 10005;

LL dp[2][maxn];

int n,notpm[maxn], pm[maxn], pcnt=0;
void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=n;i++){
		if(!notpm[i])pm[++ pcnt] = i;
		for(int j=1;j<=pcnt && i*pm[j] <= n;j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] == 0)break;
		}
	}
}

signed main(){
	int mod;
	scanf("%d%d",&n,&mod);
	xxs();
	dp[0][0] = 1;
	for(int i=1;i<=pcnt;i++){
		memcpy(dp[i&1], dp[i&1^1], sizeof dp[i&1]);
		int pp = pm[i];
		while(pp <= n){
			for(int j=pp;j<=n;j++)
				(dp[i&1][j] += 1ll * dp[i&1^1][j - pp] * pp) %= mod;
			pp *= pm[i];
		}
	}
	LL ans = 0;
	for(int i=1;i<=n;i++)(ans += dp[pcnt&1][i])%=mod;
	printf("%lld\n",ans + 1);

	return 0;
}


