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

int n,k;
ll m;
int a[maxn];

int check(int lim){
	std::vector<int> b(n+2, 0);
	for(int i=1;i<=n;i++)
		if(a[i] >= lim)b[i] = 1;
	for(int i=1;i<=n;i++)
		b[i] += b[i-1];
	int lf = 1;
	ll r = 0;
	for(int i=k;i<=n;i++){
		if(b[i] - b[lf-1] < k)continue;
		while(b[i] - b[lf] >= k)
			++ lf;
		r += lf;
	}
	return r >= m;
}

void solve(){
	scanf("%d%d%lld",&n,&k,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	// printf("%d %d\n",check(3),check(4));
	int l=0, r=1e9, ans = 1e9;
	while(l <= r){
		int mid=l+r>>1;
		if(check(mid))ans = mid, l = mid+1;
		else r = mid-1;
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

