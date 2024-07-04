// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, mod = 1e9+7;

int notpm[maxn], pm[maxn], pcnt=0, md = 2e5;
int mu[maxn];
int f[maxn], a[maxn], G[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

void xxs(){
	notpm[1] = 1;
	mu[1] = 1;
	
	for(int i=2;i<=maxn-5;i++){
		if(!notpm[i]){
			pm[++ pcnt] = i;
			mu[i] = -1;
		}
		for(int j=1;pm[j]*i<=maxn-5;j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] == 0){
				mu[i*pm[j]] = 0;
				break;
			}
			mu[i*pm[j]] = -mu[i];
		}
	}
}

int mp[maxn], n;

signed main(){
	xxs();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[a[i]] = 1;
		int tmp = a[i];
		for(int j=2;j*j<=a[i];j++){
			if(tmp%j == 0){
				int cc = 0;
				while(tmp%j == 0){
					cc ^= 1;
					tmp /= j;
				}
				if(cc)f[a[i]] *= j;
			}
		}
		if(tmp != 1)f[a[i]] *= tmp;
		++ mp[f[a[i]]];
	}
	for(int i=1;i<=md;i++){
		G[i] = 0;
		for(int j=i;j<=md;j+=i){
			if(mp[j]){
				G[i] += 1ll * mp[j] * j % mod,
				G[i] %= mod;
			}
		}
		G[i] = 1ll*G[i]*G[i] % mod;
	}
	
	int ans = 0;
	for(int i=1;i<=md;i++){
		int res = 0;
		for(int j=i;j<=md;j+=i){
			(res += 1ll*G[j]*mu[j/i]%mod) %= mod;
		}
		res = 1ll * res * pw(1ll*i*i%mod,mod-2) % mod;
		(ans += res) %= mod;
	}
	ans -= n;
	ans = 1ll * ans * pw(2, mod-2) % mod;
	ans = (ans%mod + mod) % mod;
	printf("%d\n",ans);

	return 0;
}

