// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f;

int c[12],n,dp[100005],d[14];

int popc(int x){
	int r=0;
	while(x){r += x&1; x >>= 1;}
	return r;
}

signed main(){
	for(int i=1;i<=4;i++)scanf("%lld",&c[i]);
	scanf("%lld",&n);
	dp[0] = 1;
	for(int j=1;j<=4;j++){
		for(int i=c[j];i<=100000;i++)
				dp[i] += dp[i - c[j]];
	}
	
	while(n --){
		for(int i=1;i<=4;i++)scanf("%lld",&d[i]);
		int s;
		scanf("%lld",&s);
		
		LL ans = 0;
		for(int i=0;i<=15;i++){
			int pc = popc(i), r1 = 0;
			int fpc = (pc & 1) ? -1 : 1;
			for(int j=1;j<=4;j++)
				if(i & (1<<(j-1)))r1 += c[j] * (d[j] + 1);
			if(s >= r1)ans += 1ll * fpc * dp[s - r1];
		}
		printf("%lld\n",ans);
	}

	return 0;
}


