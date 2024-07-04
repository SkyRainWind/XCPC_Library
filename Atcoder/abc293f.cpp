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

ll mysqrt(ll x,int t){
	ll l=1,r=(ll)pow(x,1.0/t) + 3,ans;
	while(l <= r){
		ll mid = (l+r)/2;
		ll h=1, gg=0;
		for(int i=1;i<=t;i++){
			if(h>x/mid+1){gg = 1;break;} 
			h*=mid;
			if(h>x){gg=1;break;}
		}
		if(gg || h > x)r = mid-1;
		else l = mid+1, ans = mid;
	}
	return ans;
}

int check(ll n,int x){
	while(n){
		int t = n%x;
		if(t >= 2)return 0;
		n /= x;
	}
	return 1;
}

int check2(ll n,int S){
	ll l=1, r=1e18, ans = -1, rr;
	while(l <= r){
		ll mid = (l+r)/2;
		ll res = 0;
		int T = S;
		ll bs = 1;
		int pre = 0, gg = 0;
		while(T){
			if(T & 1){
//				if(S == 4)printf("?? %lld %lld\n",pre,bs);
				if(pre){
					gg = 1;
					break;
				}
				res += bs;
				if(res > n)break;
			}
			T >>= 1;
			if(pre)continue;
			
			if(bs > n/mid)pre = 1;
			bs = bs * mid;
			if(bs > n)pre = 1;
		}
		if(res > n || gg)r = mid-1;
		else l = mid+1, ans = mid, rr = res;
	}
//	if(ans > 1000 && rr == n)printf("?? %lld %lld %d\n",n,ans,S);
	return ans > 1000 && rr == n;
}

void solve(){
	ll n;cin >> n;
	int ans = 0;
	for(int i=2;i<=1000;i++){
		if(check(n,i))++ ans;
	}
//	printf("!! %d\n",ans);
	for(int S = 2;S<=(1<<7)-1;S++){
		if(check2(n,S))++ ans;
	}
	cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;cin>>te;
	while(te --)solve();

	return 0;
}

