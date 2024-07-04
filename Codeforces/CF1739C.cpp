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

const int inf = 1e9, INF = 0x3f3f3f3f, mod =998244353;

int fac[65], inv[65];

int pw(int x,int y){
	if(y == 0)return 1;
	if(y == 1)return x;
	int mid = pw(x, y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){
	return 1ll * fac[x] * inv[x-y] % mod * inv[y]%mod;
}

void solve(){
	int n;scanf("%d",&n);
	int r1 = 0, r2 = 0;
	int cur = n -1 ;
	for(int i = n/2 -1,p=1; i>=1; i--,p++){
		if(i == n/2-1)r1 += C(cur,i), --cur;
		else{
			if(p&1)r1 += (C(cur, i)+C(cur-1,i))%mod;
			else r2 += (C(cur,i)+C(cur-1,i))%mod;
			cur -= 2;
		}
		r1 %= mod, r2 %= mod;
	}
	if(n%4 == 0)++ r2;
	else ++ r1;
	if(n%4 == 0)++ r2;
	else if(n>2)++ r1;
	printf("%d %d 1\n",r1,r2);
}

signed main(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=60;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[60] = pw(fac[60], mod -2 );
	for(int i=59;i>=1;i--)inv[i] = 1ll * inv[i+1]*(i+1)%mod;
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


