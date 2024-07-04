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
int n;
LL dp[(1<<24) + 5];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[5];
		scanf("%s",s+1);
		int S = 0;
		for(int i=1;i<=3;i++){
			int ch = s[i] - 'a';
			S |= (1<<ch);
		}
		++ dp[S];
	}
	for(int i=0;i<=23;i++)
		for(int S=(1<<24)-1;S>=0;S--){
			if(S&(1<<i))dp[S] += dp[S ^ (1<<i)];
	}
	int ans=0;
	for(int i=0;i<=(1<<24)-1;i++)
		ans ^= (n-dp[i])*(n-dp[i]);
//		printf("%d %d\n",n-dp[i],ans);
	printf("%d\n",ans);

	return 0;
}
