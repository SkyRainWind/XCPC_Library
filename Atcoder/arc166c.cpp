// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod=998244353,maxn=2e6+5;

int f[maxn], pre[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

void solve(){
	int n,m;scanf("%d%d",&n,&m);
	if(n < m)swap(n,m);
	ll ans = 1ll*pre[m]*pre[m]%mod*pw(f[2*m+2],n-m)%mod;
	printf("%lld\n",ans);
}

signed main(){
	f[1] = f[2] = 1;
	for(int i=3;i<=2000001;i++)f[i] = (f[i-1] + f[i-2]) % mod;
	pre[0] = 1;
	for(int i=1;i<=1000000;i++)pre[i] = 1ll*pre[i-1]*f[i*2+1]%mod;
	int te;scanf("%d",&te);while(te--)solve();

	return 0;
}

