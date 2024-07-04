// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e7+5, mod = 1e9+7;

char s[maxn];
int fac[maxn], inv[maxn];
int pre[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}
int n;

int C(int x,int y){
	return 1ll * fac[x] * inv[y] % mod * inv[x-y] % mod;
}

signed main(){
	scanf("%s",s + 1);
	n = strlen(s + 1);
	fac[0] = inv[0] = 1;
	for(int i=1;i<=maxn-5;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[maxn-5] = pw(fac[maxn-5], mod-2);
	for(int i=maxn-6;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	assert(C(5,3) == 10);
	
	for(int i=1;i<=n;i++)pre[i] = pre[i-1] + (s[i] == '1');
	for(int i=1;i<=n;i++)if(s[i] == '1'){
		// pc[0+pre[i]] += C(n-i, 0)  pc[1+pre[i]] += C(n-i,1) ...
		// C(n-i, 0) * fib[0+pre[i]] + C(n-i, 1) * fib[1+pre[i]]
		// C(n-i, 0) * fib[0+pre[i]] + C(n-i, 1) * 
		// pre[i] ... pre[i] + n - i
	}

	return 0;
}


