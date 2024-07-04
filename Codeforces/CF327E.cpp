// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=35, mod = 1e9+7;

int n, a[maxn];
int k, ban[maxn];
int dp[(1<<24) + 5], num[(1<< 24)+5], ok[(1<<24) + 5]; 
vector<int>popc[maxn];
unordered_set<int>ck;

int lowbit(int x){return x & -x;}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), num[1 << i-1] = a[i];
	scanf("%d",&k);
	for(int i=1;i<=k;i++)scanf("%d",&ban[i]), ck.insert(ban[i]);
	for(int S = 1;S<=(1<<n)-1;S++){
		for(int i = S;i;i-=lowbit(i))
			num[S] = num[S & ~lowbit(i)] + num[lowbit(i)];
		if(ck.count(num[S]))ok[S] = 0;
		else ok[S] = 1;
	}
	dp[0] = 1;
	for(int S=1;S<=(1<<n) - 1;S++)if(ok[S]){
		for(int i = S;i;i -= lowbit(i)){
			(dp[S] += dp[S & ~lowbit(i)]);
			if(dp[S] >= mod)dp[S] -= mod;
		}
	}
	printf("%d\n",dp[(1<<n) - 1]);

	return 0;
}


