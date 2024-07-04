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
const ll ini = 450283905890997363ll;

int f[100005]; 

ll pw(int x){
	if(x==0)return 1;
	if(x==1)return 3;
	int mid=pw(x>>1);
	if(x&1)return 3ll*mid*mid;
	return 1ll*mid*mid;
}

ll getf(ll x){
	if(x <= 100000)return f[x];
	if(x%3 == 0)return getf(x/3) + 1;
	if(x%3 == 1)return getf(x/3) + 2;
	if(x%3 == 2)return getf(x/3) + 3;
}

void solve(){
	ll l,r;cin>>l>>r; 
	int bs = 37;
	ll nw = ini;
	ll ans=0;
	for(int i=37;i>=1;i--, nw/=3){
		if(r%nw == nw-1){
			ans = max(ans, getf(r));
			r = l-1;
			break;
		}else if(l%nw == nw-1){
			ans = max(ans, getf(l));
			l ++;
		}
		if((l+1) / nw != (r+1) / nw){
//			printf("%lld %lld %lld\n",l,r,nw);
			ll t = (r+1) / nw;
			t = nw * t;
			-- t;
			ans = max(ans, getf(t));
			l = t+1;
			continue;
		}
	}
	while(l <= r)ans = max(ans, getf(l)), l++;
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0]=1;
	for(int i=1;i<=100000;i++)f[i]=(i%3==0)?(f[i/3]+1):(f[i-1]+1);
	int te;
	cin>>te;
	while(te --)solve();
	
	return 0;
}

