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

vector<int>v[300005];int n; 
void solve(){
	scanf("%d",&n);
	vector<int>a(n+3), l(n+3), r(n+3);
	vector<ll> num(n+10, 0);
	for(int i=0;i<=n+1;i++)v[i].clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)v[a[i]].pb(i);
	for(int i=0;i<=n+1;i++)l[i] = i-1, r[i] = i+1;
	for(int i=1;i<=n;i++){
		for(int u : v[i-1]){
			int tp = n;
			if(r[u] <= n)tp = min(tp, a[r[u]]);
			if(l[u] >= 1)tp = min(tp, a[l[u]]);
			num[r[u] - l[u] - 1] += tp - i+1;
			l[r[u]] = l[u], r[l[u]] = r[u];
		}
	}
	
	ll m,ans = 0;cin >> m;
	for(int i=n;i>=1;i--){
		if(!m)break;
		if(m >= 1ll * num[i] * i)m -= 1ll*num[i]*i, ans += 1ll * (num[i]) * (i-1);
		else{
			ans += (m/i) * (i-1);
			m %= i;
			if(m)ans += m-1;
			break;
		}
	}
	cout << ans << '\n';
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve(); 

	return 0;
}

