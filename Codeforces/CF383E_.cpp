// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = (1<<24)+5;
int n,dp[maxn];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[5];scanf("%s",s+1);
		int S = 0;
		for(int i=1;i<=3;i++){
			S |= (1<<s[i]-'a');
		}
		S ^= (1<<24)-1;
		++ dp[S];
	}
	for(int i=0;i<=23;i++)
		for(int S=0;S<=(1<<24)-1;S++)
			if((S & (1<<i)) == 0)dp[S] += dp[S ^ (1<<i)];
	
	int ans=0;
	for(int i=0;i<(1<<24);++i)
		ans ^= (n-dp[i]) * (n-dp[i]);
	printf("%d\n",ans);

	return 0;
}

