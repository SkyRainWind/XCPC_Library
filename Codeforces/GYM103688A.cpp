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

int a,b,h,n,m;

int check(int lim){
	int t = n/b, tt = n%b;
	ll t1 = 1ll*t*(h-a);
	int t2 = (m-lim) + tt;
	t2 = t2 / b;
	ll t3 = 1ll*t2*(h-b);
	return t1+t3>=1ll*lim;
}

void solve(){
	scanf("%d%d%d%d%d",&a,&b,&n,&m,&h);
	int l=1,r=m-1,ans=0;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",n+m-ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

