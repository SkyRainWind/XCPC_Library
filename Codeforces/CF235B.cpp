// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5 + 5;
int n;
double p[maxn],f[maxn],g[maxn];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++){
		f[i] = (f[i-1] + 1) * p[i];
		g[i] = g[i-1] + (2*f[i-1] + 1) * p[i];
	}
	printf("%.6f\n",g[n]);

	return 0;
}

