// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5, mod = 1e9+7;

int n, a[maxn], dp[1000005];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j == 0 && j*j != a[i])
				(dp[a[i] / j] += dp[a[i] / j - 1]) %= mod;
		for(int j=(int)sqrt(1.0 * a[i]);j>=1;j--){
			if(a[i]%j == 0){
				(dp[j] += dp[j - 1] ) %= mod;
			}
		}
		++ dp[1];
	}
	int ans = 0;
	for(int i = 1;i<=(int)n;i++)(ans += dp[i]) %= mod;
	printf("%d\n",ans);

	return 0;
}


