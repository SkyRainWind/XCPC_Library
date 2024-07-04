// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e6+5;

int n,mod=998244353;

int fac[maxn],inv[maxn];
int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}

signed main(){
	scanf("%d%d",&n,&mod);
	fac[0] = inv[0] = 1;
	for(int i=1;i<=maxn-5;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[maxn-5]=pw(fac[maxn-5],mod-2);
	for(int i=maxn-6;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	
	ll t1 = (2ll*fac[2*n]%mod - fac[n]%mod - 1 + mod)%mod;
	ll t2 = (1ll*fac[n]*C(2*n,n)-1)%mod*(1ll*(C(2*n,n)-1)*fac[n]%mod)%mod*fac[n]%mod;
	(t2 += 1ll*(fac[n]-1)*(fac[2*n]-fac[n]+mod)%mod) %= mod;
	
	for(int k=1;k<=n;k++){
		ll tmp = 1ll*C(n,k)*C(n,n-k)%mod;
		tmp = tmp*(fac[2*n]-1ll*C(n,k)*fac[k]%mod*fac[2*n-k]%mod+mod)%mod*fac[n]%mod;
		(t2 += tmp) %= mod;
	}
	ll t3 = (fac[3 * n] - 1 - t1 + mod - t2 + mod) % mod;
	ll ans = (t1 + 2ll*t2%mod + 3ll*t3%mod) % mod;
	cout<<ans;
	
	return 0;
}

