// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#include <cmath>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f;

LL m;
int n,lcm[72][72];

int myp(int x,int k){
	int r=1;
	for(int i=1;i<=k;i++){
		r*=x;
		if(r>=1e17)return 1e17;
	}
	return r;
}

int mysqrt(int x,int k){	// sqrt_k(x)
	int pre=pow(x,1.0/k);
	while(myp(pre,k)<x)++pre;
	while(myp(pre,k)>x)--pre;
	return pre;
}

int a[200005],dp[72][72];
int popc(int S){
	int cn = 0;
	while(S){cn += S & 1; S >>= 1;}
	return cn;
}

LL gcd(LL a,LL b){return !b ? a : gcd(b, a%b);}
LL Lcm(LL x,LL y){
	return 1ll * x * y / gcd(x, y);
}

int check(LL lim){
	LL ans = 0;
	for(int i=1;i<=65;i++)ans += dp[n][i] * mysqrt(lim,i);
	return ans >= m;
}

void solve(){
	memset(dp, 0, sizeof dp);
	scanf("%lld%lld",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dp[0][1] = -1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=65;j++){
			dp[i][lcm[a[i]][j]] -= dp[i-1][j];	
			dp[i][j] += dp[i-1][j];		
		}
	}
	++ dp[n][1];
	LL l = 1, r = 1e17, ans;
	while(l <= r){
		LL mid = l+r>>1;
		if(check(mid))r = mid-1, ans = mid;
		else l = mid+1;
	}
	printf("%lld\n",ans);
}

signed main(){
//	freopen("zr1155.in","r",stdin);
	for(int i=1;i<=65;i++)
		for(int j=1;j<=65;j++){
			int t = Lcm(i,j);
			if(t >= 65)t = 65;
			lcm[i][j] = t;
		}
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


