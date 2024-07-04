// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1000003, maxn = 305;

int n,a[maxn],prod[maxn],iprod[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod; 
}

ll dp[305][305];
int mul(int x,int y){
	return 1ll*prod[y]*iprod[x-1]%mod;
}

ll get(int l,int k,int r){
	ll s1 = mul(l,k);
	ll s2 = mul(k+1,r);
	return 1ll*(s1-s2)*(s1-s2); 
}

signed main(){
	scanf("%d",&n);
	prod[0] = iprod[0] = 1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), prod[i] = 1ll * prod[i-1] * a[i] % mod;
	for(int i=1;i<=n;i++)
		iprod[i] = pw(prod[i], mod-2);
	for(int i=1;i<=n;i++)dp[i][i] = 0;
	
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j = i+l-1;
			for(int k=i;k<j;k++){
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + get(i,k,j));
			}
		}
	}
	cout << dp[1][n] << '\n';

	return 0;
}

