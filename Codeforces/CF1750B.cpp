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

const int inf = 1e9, INF = 0x3f3f3f3f;

int n;
char s[200005];

void solve(){
	scanf("%d",&n);
	scanf("%s", s +1);
	int t1=0, t0=0;
	for(int i=1;i<=n;i++)if(s[i] == '1')++ t1;else ++ t0;
	int cnt = 1;
	LL ans = 1ll * t1 * t0;
	for(int i=1;i<=n;i++)
		if(s[i] == s[i-1])++ cnt;
		else{ans = max(ans, 1ll * cnt * cnt);cnt =1 ;}
	ans = max(ans, 1ll * cnt * cnt);
	printf("%I64d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

