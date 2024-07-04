// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n;
pii a[maxn];
ll sx, sy;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second),
		sx += a[i].first,
		sy += a[i].second;
	sort(a+1,a+n+1,[&](pii a,pii b){
		return 1ll * a.first * sy - 1ll * a.second * sx > 1ll * b.first * sy - 1ll * b.second * sx;
	});
	ll tx=0, ty=0;
	double ans = 0.0;
	for(int i=1;i<n;i++){
		tx += a[i].first, ty += a[i].second;
		ans = max(ans, 1.0 * (1ll * tx * sy - 1ll * ty * sx) / i / (n-i));
	}
	// sort(a+1,a+n+1,[&](pii a,pii b){
	// 	return a.first * sy - a.second * sx < b.first * sy - b.second * sx;
	// });
	// tx=0, ty=0;
	// for(int i=1;i<=n;i++){
	// 	tx += a[i].first, ty += a[i].second;
	// 	ans = max(ans, -1.0 * (tx * sy - ty * sx) / i / (n-i));
	// }
	printf("%.10f\n",ans / 2.0);

	return 0;
}
