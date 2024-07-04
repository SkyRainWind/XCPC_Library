// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353, maxn = 2e6+5;

ll n;
int k; 
int fac[maxn],inv[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod * inv[x-y]%mod;
}

void solve(){
	scanf("%lld%d",&n,&k);
	ll sz = n / (2*k), rem = n % (2*k);
	ll ans1 = sz*(sz-1)/2 * (2*k) + (sz) * rem;
	ll ans2 = 0;
	if(k*2 >= n){
		printf("0 %d\n",C(k-1, n-k-1));
		return ;
	}
	for(int i=0;i<=rem;i++){
		int other = rem - i*2;
		if(other < 0 || i > k-1 || k+1-i < other)continue;
		(ans2 += 1ll*C(k-1,i)*C(k+1-i,other)%mod) %= mod;
	}
	printf("%lld %lld\n",ans1,ans2);
}

signed main(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=maxn-5;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[maxn-5] = pw(fac[maxn-5], mod-2);
	for(int i=maxn-6;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

