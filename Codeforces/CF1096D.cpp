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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n;
char s[maxn];
int a[maxn];
LL dp[maxn][4];

void ck(LL &p,LL q){p = min(p,q);} 

signed main(){
	scanf("%d",&n);
	scanf("%s", s+ 1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=3;j++)dp[i][j] = inf;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		if(s[i] != 'h' && s[i] != 'a' && s[i] != 'r' && s[i] != 'd'){
			for(int j=0;j<=3;j++)dp[i][j] = dp[i-1][j];
			continue;
		}
		for(int j=0;j<=3;j++)dp[i][j] =dp[i-1][j] + a[i];
		if(s[i] == 'h'){
			ck(dp[i][1], dp[i-1][0]);
			for(int j=1;j<=3;j++)ck(dp[i][j], dp[i-1][j]);
		}
		if(s[i] == 'a'){
			ck(dp[i][2], dp[i-1][1]);
			ck(dp[i][2], dp[i-1][2]);
			ck(dp[i][0], dp[i-1][0]);
			ck(dp[i][3], dp[i-1][3]);
		}
		if(s[i] == 'r'){
			ck(dp[i][3],dp[i-1][2]);
			ck(dp[i][3],dp[i-1][3]);
			ck(dp[i][1],dp[i-1][1]);
			ck(dp[i][0],dp[i-1][0]);
		}
		if(s[i] == 'd'){
			ck(dp[i][2],dp[i-1][2]);
			ck(dp[i][1],dp[i-1][1]);
			ck(dp[i][0],dp[i-1][0]);
		}
	}
	LL m4 = min(min(dp[n][0], dp[n][1]), min(dp[n][2],dp[n][3]));
	printf("%lld\n",m4);

	return 0;
}
