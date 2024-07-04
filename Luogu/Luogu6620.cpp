// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,x,mod,m;
int S[1005][1005];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}
int C[1005][1005],a[1005];

signed main(){
	scanf("%d%d%d%d",&n,&x,&mod,&m);
	for(int i=0;i<=m;i++)scanf("%d",&a[i]);
	S[1][1] = 1;
	for(int i=2;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			(S[i][j] = S[i-1][j-1]+1ll*j*S[i-1][j]%mod) %= mod;
	C[0][0] = 1;
	for(int i=1;i<=1000;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	
	ll ans = 1ll * a[0] * pw(x+1, n) % mod;
	for(int p=1;p<=m;p++){
		int cans = 0, ndown = n;
		for(int i=1;i<=p;i++){
			(cans += 1ll * ndown * S[p][i] % mod * pw(x,i) % mod * pw(1+x,n-i) % mod) %= mod;
			ndown = 1ll*ndown * (n-i) % mod;
		}
		(ans += 1ll*cans*a[p]%mod) %= mod;
	}
	cout<<ans;

	return 0;
}

