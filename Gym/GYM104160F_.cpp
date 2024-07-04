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

void sv(ll m,ll n,int op=1){
	ll cur = m*(m+1)/4;
	ll tmp = 0;
	int cnt=0;
	vector<int>res;
	int f=0,k=m-cnt;
	while(1){
		if(cur == m-cnt){
			while(cur--)res.pb(f),f^=1;
			break;
		}
		// cur > m-cnt
		ll l=1,r=m-cnt,re=0;
		while(l<=r){
			ll mid=l+r>>1;
			if(cur-mid*(mid+1)/2 >= m-cnt-mid)re=mid,l=mid+1;
			else r=mid-1;
		}
		cnt += re;
		cur -= re*(re+1)/2;
		while(re--)res.pb(f);
		f^=1;
	}
	if(op)
		for(int i=1;i<=n;i++){
			for(auto it : res)printf("%d ",it);puts("");
		}
	else
		for(auto it : res){
			for(int i=1;i<=n;i++)printf("%d ",it);puts("");
		}
}

void solve(ll n,ll m){
	if(m*(m+1)%4 != 0 && n*(n+1)%4 != 0){puts("No");return ;}
	puts("Yes");
	if(m*(m+1)%4 == 0)sv(m,n,1);
	else sv(n,m,0);
}

void solve(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	solve(n,m);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

