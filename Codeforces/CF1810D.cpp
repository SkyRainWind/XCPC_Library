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

int in(ll x,ll a,ll b){
	return x>=a && x<=b;
}

ll go(ll a,ll b,ll x){
	if(x < 0)return 0;
	return 1ll*(a-b)*x+a;
}

void solve(){
	int q;
	scanf("%d",&q);
	ll up = 1e18, dn = 0;
	while(q --){
		int op;scanf("%d",&op);
		if(op == 1){
			int a,b,n;scanf("%d%d%d",&a,&b,&n);
			ll nup = 1ll*(a-b)*(n-1)+a, ndn = 1ll*a*(n-1)-1ll*b*(n-2)+1;
			if(n == 1){
				nup = a;
				ndn = 1;
			}
			if(nup < dn || ndn > up)printf("0 ");
			else{
				up = min(nup, up);
				dn = max(ndn, dn);
				printf("1 ");
			}
		}else{
			int a,b;scanf("%d%d",&a,&b);
			ll l = 1, r = 1e18/(a-b), res=0;
			while(l <= r){
				ll mid = (l+r)/2;
				ll now = 1ll*(a-b)*(mid-1)+a;
				if(go(a,b,mid-2)<dn && go(a,b,mid-1)>=dn){
					res = mid;
					break;
				}
				if(go(a,b,mid-2) >= dn)r = mid-1;
				else l = mid+1;
			}
//			printf("?? %lld - %lld %lld\n",dn,up,res);
			ll n1 = go(a,b,res-1);
			ll n2 = 1ll*(a-b)*(res);
			if(n1+1 <= up)printf("-1 ");
			else printf("%lld ",res);
		}
	}
	puts("");
}

signed main(){
//	freopen("CF1810D.in","r",stdin);
	int te;scanf("%d",&te);
	while(te --)solve(); 

	return 0;
}

