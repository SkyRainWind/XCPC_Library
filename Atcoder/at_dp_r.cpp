// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7;

int n;ll k;
struct mat{
	ll a[52][52];
	mat(){memset(a,0,sizeof a);}
};
mat b;

mat operator * (mat a, mat b){
	mat c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				(c.a[i][j] += a.a[i][k] * b.a[k][j] % mod) %= mod;
	return c;
}

mat pw(mat b, ll k){
	mat bs = b, c = b;-- k;
	while(k){
		if(k&1)c = c * bs;
		bs = bs * bs;
		k >>= 1;
	}
	return c;
}

signed main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)cin >> b.a[i][j];
	
	mat now = pw(b, k);
	
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)(ans += now.a[i][j]) %= mod;
	cout<<ans;

	return 0;
}

