// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e6 + 5, mod = 998244353;

int n;
char s[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	int p100 = pw(100, mod-2);
	scanf("%d",&n);
	scanf("%s",s + 1);
	
	vector<int>p(n+2);
	for(int i=1;i<=n-1;i++)scanf("%d",&p[i]),p[i] = 1ll*p[i]*p100%mod;
	
	ll ans = 0;
	vector<int>coef(n+2);
	coef[n] = 1;
	for(int i=n-1;i>=1;i--){
		coef[i] = 10ll * (mod+1 - p[i])%mod * coef[i+1]%mod;
		(coef[i] += p[i]) %= mod;
	}
	for(int i=1;i<=n;i++)
		(ans += 1ll * coef[i] *(s[i]-'0')%mod) %= mod;
	cout << ans << '\n';

	return 0;
}

