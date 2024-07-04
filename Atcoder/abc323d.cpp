// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n;
int a[maxn],b[maxn],m;
map<ll,int>dp;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]), dp[a[i]] = b[i];
	int res = 0;
	for(auto it : dp){
		dp[it.first*2ll] += it.second / 2;
		if(it.second%2 == 1)++ res;
	}
	printf("%d\n",res);
	
	return 0;
}

