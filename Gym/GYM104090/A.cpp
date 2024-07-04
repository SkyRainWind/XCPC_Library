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

int n,m;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	ll gd = exgcd(b,a%b,x,y);
	ll t = x;x = y;y = t-a/b*y;
	return gd;
}

signed main(){
	ll sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		sum += x;
	}
	
	ll a = n, b = 1ll*n*(n+1)/2,x,y,k,t;
	ll p = exgcd(a,b,x,y);
	ll g = exgcd(p,m,k,t);
	ll C = ((m-sum%m-1) / g+1) * g;
	ll c = C / g;
	printf("%lld\n%lld %lld\n",(C+sum)%m,(x*k%m*c%m+m)%m,(y*k%m*c%m+m)%m);

	return 0;
}

