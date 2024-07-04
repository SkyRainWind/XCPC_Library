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

int notpm[maxn], pm[maxn], pcnt=0;
ll f[maxn];

void xxs(){
	notpm[1] = f[1] = 1;
	for(int i=2;i<=maxn-5;i++){
		if(!notpm[i]){
			pm[++pcnt]=i;
			f[i] = 1;
		}
		for(int j=1;j<=pcnt && 1ll*pm[j]*i<=maxn-5;j++){
			notpm[i*pm[j]] = 1;
			int cc = i*pm[j], qw = 1;
			while(cc % pm[j] == 0){
				cc /= pm[j];
				qw *= pm[j];
			}
			if(cc == 1)f[i*pm[j]] = 1ll * pm[j] * f[i/pm[j]];
			else f[i*pm[j]] = 1ll * f[qw] * cc;
			if(i%pm[j] == 0){
				break;
			}
		}
	}
}

signed main(){
	xxs();
	int n;scanf("%d",&n);
	ll ans = 0;
	
	for(int i=1;i<=n;i++)ans += f[i];
	cout << ans << '\n';

	return 0;
}

