// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5+5, mod =998244353;

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
	
	int n;
	scanf("%d",&n);
	int res = 1;
	for(int i=1;i<=n/3;i++){
		int a[4];
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		sort(a+1,a+4);
		if(a[1]==a[2]&&a[2]==a[3]){
			res=3ll*res%mod;
			continue;
		}
		if(a[2]==a[3]){
			continue;
		}
		if(a[1]==a[2]){
			res=2ll*res%mod;
			continue;
		}
	}
	res=1ll*res*C(n/3,n/6)%mod;
	cout << res << '\n';

	return 0;
}

