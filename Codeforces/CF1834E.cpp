// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e7, INF = 0x3f3f3f3f, maxn = 3e5+5;

ll lcm(int a,int b){
	return 1ll * a / __gcd(a,b) * b;
}

int n,a[maxn];

bitset<inf+5>vis;
void solve(){
	for(int i=1;i<=n*30;i++)vis[i]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	vector<ll>v;
	for(int i=1;i<=n;i++){
		for(auto &t : v)
			t = lcm(t, a[i]);
		v.pb(a[i]);
		vector<ll>tmp;
		tmp.pb(v[0]);
		for(auto u : v)
			if(tmp.back() != u)tmp.pb(u);
		swap(v, tmp);
		while(v.size() && v[0] >= inf)v.erase(v.begin());
		for(ll i : v)vis[i]=1;
	}
	int f;
	for(int i=1;;i++){
		if(!vis[i]){
			f=i;
			break;
		}
	}
	cout << f << '\n';
}

signed main(){
	int te;
	scanf("%d",&te);
	while(te --)solve();

	return 0;
}
