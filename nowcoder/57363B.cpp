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

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	ll ret = exgcd(b,a%b,x,y);
	ll t=x;x=y;y=t-a/b*y;
	return ret;
}

ll getphi(ll n){
	ll ph = n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0)n/=i;
			ph = ph / i * (i-1);
		}
	}
	if(n!=1)ph = ph / n * (n-1);
	return ph;
}

ll pw(ll a, ll b, ll p) {
    ll res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

ll solve(ll w,ll a,ll m){
	if(m==1){
		return 0;
	}
	if(w==0)return 0;
	ll y = getphi(m);
	ll t,k;
	ll gd = exgcd(y,m,t,k);
//	printf("%lld %d %d %d\n",gd,w,a,m);
	ll A = pw(a,y,gd)*w%gd;
	ll r = solve(A,a,gd)%y;
	t = (t%m+m)%m;
	t = t * 1ll * (1ll*w*(pw(a%m,y+r,m))%m-r+m)%m;
	if(t==0)t=m;
	t = t / gd; 
	return t*y+r;
}

void solve(){
	int a,m;
	scanf("%d%d",&a,&m);
	ll t = solve(1,a,m);
	printf("%lld\n",t);
}

signed main(){
//	printf("%d %d\n",pw(114514,3978768656,1919810),3978768656%1919810);
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

