// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7;

int C[3005][3005];
int a[3005], n;

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	C[0][0] = 1;
	for(int i=1;i<=3000;i++){
		C[i][0] = 1;
		for(int j=1;j<=3000;j++)
			(C[i][j] = C[i-1][j] + C[i-1][j-1]) %= mod;
	}
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int del = a[j] - a[i];
			int lb = lower_bound(a+1, a+n+1, a[i] - del) - a - 1;
			int ub = lower_bound(a+1, a+n+1, a[j] + del) - a;
//			printf("%d %d\n",lb,ub);
//			if(a[n] <= a[j]+del)ub = n;
			ub = n - ub + 1;
			(ans += pw(2, lb+ub)) %= mod;
		}
	}
	cout << ans << '\n';

	return 0;
}

