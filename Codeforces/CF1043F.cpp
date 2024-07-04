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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 + 5;
const int mod = 998244353;

int n;
int a[maxn];
int notpm[maxn], pm[maxn], pcnt = 0;
int cnt[maxn], dp[maxn];

void xxs(){
	int lm = 3e5;
	notpm[1] = 1;
	for(int i=2;i<=lm;i++){
		if(!notpm[i]){
			pm[++ pcnt] = i;
		}
		for(int j=1;j<=pcnt && i*pm[j] <= lm;j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] == 0)break;
		}
	}
}
int fac[maxn],inv[maxn];
int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid = pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}
int C(int x,int y){
	if(x == 0)return 0;
	if(x < y)return 0;
	return 1ll*fac[x]*inv[x-y]%mod*inv[y]%mod;
}

signed main(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=300000;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[300000] = pw(fac[300000], mod-2);
	for(int i=299999;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	xxs();
	vector<int>vc;
	for(int i=1;i<=n;i++){
		int cur = a[i];
		for(int j=1;j*j<=cur;j++){
			if(a[i] % j == 0){
				++ cnt[j];
				if(j*j != a[i])++ cnt[a[i] / j];
			}
		}
	}
	for(int i=300000;i>=1;i--)if(cnt[i])vc.push_back(i);
	for(int len = 1;len<=7;len++){
		memset(dp, 0, sizeof dp);
		for(int i : vc){
			int cc = C(cnt[i], len);
			if(cc == 0)continue;
			dp[i] = cc;
			for(int j=2*i;j<=300000;j+=i)
				(dp[i] += (mod - dp[j])%mod) %= mod;
		}
		if(dp[1])return printf("%d\n",len), 0;
	}
	puts("-1");

	return 0;
}


