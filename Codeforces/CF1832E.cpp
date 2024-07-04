// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
#define int ll 

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e7+5, mod = 998244353;

int n,a[maxn],x,y,m,k;
int lst[maxn], b[maxn];
//int C[maxn][6];

signed main(){
	scanf("%d%d%d%d%d%d",&n,&a[1],&x,&y,&m,&k);
	for(int i=2;i<=n;i++)a[i] = (1ll * a[i-1] * x%m + y)%m;
	for(int i=1;i<=n;i++)lst[i] = lst[i-1] + a[i];
	
	for(int t=1;t<=k;t++){
		b[1] = (t == 1) * a[1] % mod;
		for(int i=2;i<=n;i++){
			b[i] = (lst[i-1] + b[i-1]) % mod,
			(b[i] += (t == 1) * a[i]) %= mod;
		}
		for(int i=1;i<=n;i++)
			lst[i] = b[i];
	}
	ll ans = 0;
	for(int i=1;i<=n;i++)
		ans ^= (1ll * b[i] * i); 
	cout << ans << '\n';

	return 0;
}

