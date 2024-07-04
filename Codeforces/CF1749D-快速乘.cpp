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
typedef unsigned long long ULL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 + 5, mod=998244353;

int notpm[maxn], pm[maxn], pcnt=0;

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=300000;i++){
		if(!notpm[i]){
			pm[++ pcnt] = i;
		}
		for(int j=1;j<=pcnt && i * pm[j] <= 300000; j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] == 0)break;
		}
	}
}

int n;
LL m;
LL bs = 1, nbs = 1;
int gg = 0;
int tmp =1 ;
inline LL ksc(LL x,LL y,LL p){
	LL z=(long double)x/p*y;
	LL res=(ULL)x*y-(ULL)z*p;
	return (res+p)%p;
}
signed main(){
	scanf("%d%I64d",&n,&m);
	xxs();
	int pi = 1;
	LL ans = 0;
	for(int i=1;i<=n;i++){
		bs = ksc(bs, m, mod);
//		bs = 1ll * bs * m % mod;
		if(pm[pi] == i && !gg){
			nbs = 1ll * nbs * pm[pi];
			if(nbs > m){
				gg = 1;
			}
			++ pi;
		}
		(ans += bs) %= mod;
		if(!gg){
			tmp = ksc(tmp, m/nbs, mod);
//			tmp = 1ll * tmp * (m/nbs) % mod;
			(ans += mod - tmp) %= mod;
		}
//		cout << nbs << " "<< bs << " " << gg << '\n';
	}
	printf("%I64d\n",ans);

	return 0;
}

