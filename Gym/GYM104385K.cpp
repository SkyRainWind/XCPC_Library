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

signed main(){
	int n;
	scanf("%d",&n);
	vector<int>a(n+2), vc;
	vector<ll> sum(n+2);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++){
		vc.pb(a[i+1] - a[i]);
	}
	int cnt=0;
	sort(vc.begin(), vc.end(), [&](ll a,ll b){return a<b;});
	sum[0] = 0;
	for(auto it : vc){
		++ cnt;
		sum[cnt] = sum[cnt-1] + it;
	}
	int qu;scanf("%d",&qu);
	while(qu--){
		int op,x;scanf("%d%d",&op,&x);
		if(op==1)printf("%lld\n",a[1] - a[n] + sum[x-1]);
	}

	return 0;
}

