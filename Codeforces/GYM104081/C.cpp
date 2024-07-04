// r1 t > r2 t + 2 * (r1-r2) = 2 * r1 + (t-2) * r2
// r1 * (t-2) > r2 * (t-2)
// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
const double pi=3.1415926;

int n;
double r,t;
signed main(){
	scanf("%d%lf%lf",&n,&r,&t);
	double rr=2e9,ans=min(t*r,(2*pi-t)*r);
	for(int i=1;i<=n;i++){
		double tx;scanf("%lf",&tx);
		ans = min(ans, 2.0*(r-tx)+t*tx);
		ans = min(ans, 2.0*(r-tx)+(2*pi-t)*tx);
	}
	printf("%.8f\n",ans);

	return 0;
}

