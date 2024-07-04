// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353, maxn = 1e6+5;

int n,a[maxn],pre[(int)1e7 + 5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int m = a[n];
	for(int i=1;i<=m;i++)pre[i] = 0;
	for(int i=1;i<=n;i++)pre[a[i]] = 1;
	for(int i=1;i<=m;i++)pre[i] += pre[i-1];
	
	int lst = 0, ans = 0;
	for(int i=1;i<=m;i++){
		int r = 0;
		int k = m/i;
		if(m%i == 0){
			for(int j=k;j<=m;j+=k)r += pre[j] - pre[j-1];
		}else{
			if(m%(i-1) != 0 && m/(i-1) == k)r=lst;
			else{
				for(int j=1;j<k&&1ll*j*k<=m;j++)r += pre[min(j*k+j, m)] - pre[j*k-1];
				if(1ll*k*k <= m)r += pre[m] - pre[k*k - 1];
			}
		}
		(ans += 1ll*i*r%mod) %= mod;
		lst = r;
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

