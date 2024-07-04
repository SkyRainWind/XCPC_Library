// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4e5+5, mod = 998244353;

int n,k;
int a[400050], sum[400005];
int fac[maxn], inv[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}

signed main(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=maxn-5;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[maxn-5] = pw(fac[maxn-5], mod-2);
	for(int i=maxn-6;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), sum[a[i]] = 1;
	for(int i=1;i<=400000;i++)sum[i] += sum[i-1];
	
	ll ans = 0;
	for(int i=400001;i>=0;i--){
		int ned = i+1 - sum[i];
		int rst = k - ned;
		if(rst < 0)continue;
		if(i<=200000 && sum[i+1] - sum[i] > 0)continue;
//		printf("! %d\n",i);
		// x[0]+..+x[i]=rst
		(ans += C(rst+i,i)) %= mod;
	}
	cout << ans << '\n';

	return 0;
}

