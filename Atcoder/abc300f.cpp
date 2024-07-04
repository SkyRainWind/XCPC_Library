// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5+5;

int n,m;
ll k;
char s[maxn * 2];

signed main(){
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%s",s + 1);
	for(int i=n+1;i<=2*n;i++)s[i] = s[i-n];
	int c1=0;
	for(int i=1;i<=n;i++){
		if(s[i] == 'x')++ c1;
	}
	ll bs = 1ll * k / c1 * n;
	ll rst = k - 1ll * k / c1 * c1;
	int j, c0=0;
//	cout << rst << ' ' << bs << '\n';
	if(rst == 0 && bs == 1ll*n*m)
		return printf("%lld\n",bs), 0;
	int qw = 2;
	if(k/c1 == m-1)qw = 1;
	for(j=1;j<=n;j++)
		if(s[j] == 'x'){
			++ c0;
			if(c0 > rst){
				-- j;
				break;
			}
		}
//	printf("! %d\n",j);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans, j-i+1+bs);
		if(s[i] == 'x'){
			if(j < qw*n)++ j;
			while(j < qw*n && s[j+1] == 'o')++ j;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
// 3 4 3 oxo
// 2 100 3 xo
