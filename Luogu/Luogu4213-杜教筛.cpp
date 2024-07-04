// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e7+5;

int notpm[maxn],pm[maxn],pcnt=0;
ll phi[maxn],mu[maxn];
ll sphi[maxn], smu[maxn];
map<int,ll>mphi, mmu;

ll getsumphi(int n){
	if(n <= maxn-5)return sphi[n];
	if(mphi.count(n))return mphi[n];
	
	ll ret = 1ll*n*(n+1) / 2;
	for(int l=2,r;l<=n;l=r+1){
		r = n / (n/l);
		ret -= 1ll*(r-l+1)*getsumphi(n/l);
	}
	return mphi[n] = ret;
}

ll getsummu(int n){
	if(n <= maxn-5)return smu[n];
	if(mmu.count(n))return mmu[n];
	
	ll ret = 1ll;
	for(int l=2,r;l<=n;l=r+1){
		r = n / (n/l);
		ret -= 1ll*(r-l+1)*getsummu(n/l);
	}
	return mmu[n] = ret;
}

void xxs(){
	notpm[1] = 1;
	phi[1] = mu[1] = 1;
	for(int i=2;i<=maxn-5;i++){
		if(!notpm[i]){
			pm[++pcnt]=i;
			phi[i] = i-1;
			mu[i] = -1;
		}
		for(int j=1;j<=pcnt && i*1ll*pm[j] <= maxn-5;j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] == 0){
				phi[i*pm[j]] = phi[i] * pm[j];
				mu[i*pm[j]] = 0;
				break;
			}
			phi[i*pm[j]] = phi[i] * (pm[j] - 1);
			mu[i*pm[j]] = -mu[i];
		}
	}
	for(int i=1;i<=maxn-5;i++)
		smu[i] = smu[i-1] + mu[i],
		sphi[i] = sphi[i-1] + phi[i];
}

void solve(){
	int n;scanf("%d",&n);
	printf("%lld %lld\n",getsumphi(n), getsummu(n));
}

signed main(){
	xxs();
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

