// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353;

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int n,p[200005];

ll dfs(int x, ll cp, ll sp=0){
	if(x == n)return 0;
	ll coef = 1ll * p[x+1] * pw(1-p[x+1]+mod, mod-2) % mod;
//	ll np = (1ll*cp*p[x+1]%mod+1) * pw((1-p[x+1]+mod)%mod, mod-2) % mod;
	ll offset = (1ll*coef*sp%mod + pw(1-p[x+1]+mod, mod-2))%mod; 
	ll res = dfs(x + 1, offset, (sp+offset)%mod);
	return (res + offset) % mod;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		p[i] = 1ll * x * pw(y, mod-2) % mod;
	}
	ll res = dfs(0, pw(1-p[1]+mod, mod-2));
	cout << res << '\n';

	return 0;
}

