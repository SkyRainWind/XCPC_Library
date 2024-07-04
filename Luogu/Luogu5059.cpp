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

ll n, mod;

inline ll mul(ll a,ll b,ll mod){
	return (a*b-(ll)((long double)a/mod*b)*mod+mod)%mod;
}

struct mat{
	ll a[3][3];
	mat(){memset(a,0,sizeof a);}
};
mat operator * (mat a, mat b){
	mat c;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				c.a[i][j] += mul(a.a[i][k], b.a[k][j], mod),
				c.a[i][j] %= mod;
	return c;
}

mat bs;
void pw(ll y){
	mat base = bs;
	while(y){
		if(y%2 == 1)bs = bs * base;
		y/=2;
		base = base * base;
	}
}

ll pw(ll x,ll y){
	if(!y)return 1;
	if(y==1)return x%mod;
	ll mid=pw(x,y/2);
	ll qw = mul(mid,mid,mod);
	if(y%2==1)return mul(qw,x,mod);
	return qw;
}
signed main(){
	cin >> n >> mod;
	bs.a[1][1] = bs.a[1][2] = bs.a[2][1] = 1, bs.a[2][2] = 0;
	if(n == 1)return puts("0"),0;
	if(n == 2)return printf("%d\n",1%mod), 0;
	pw(n - 1);
	mat hh;
	hh.a[1][1] = 2,hh.a[2][1] = 1;
	hh.a[1][2] = hh.a[2][2] = 0;
	hh = bs * hh;
	ll res = hh.a[1][1];
	res = (res - 2 - n + mod) % mod;
	cout << pw(res, 1+n); 

	return 0;
}

