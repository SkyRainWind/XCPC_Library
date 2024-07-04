// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, mod=1e9+7;

int fac[maxn], inv[maxn];
int h,w,n;
ll dp[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
struct node{int x,y;}a[maxn];

int cmp(node a,node b){return a.x!=b.x ? a.x<b.x : a.y<b.y;}
int ck(int i,int j){
	return a[j].x <= a[i].x && a[j].y <= a[i].y;
}
ll to(int x1,int y1,int x2,int y2){
	int dx = x2-x1, dy = y2-y1;
	return C(dx+dy, dx);
}

signed main(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=maxn-5;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[maxn-5] = pw(fac[maxn-5], mod-2);
	for(int i=maxn-6;i>=0;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	a[n+1] = node{h,w};
	
	for(int i=1;i<=n+1;i++){
		dp[i] = C(a[i].x+a[i].y-2, a[i].x-1);
//		printf("! %d\n",dp[i]);
		for(int j=1;j<=n;j++)if(j != i && ck(i,j)){
			(dp[i] += mod - 1ll*dp[j]*to(a[j].x,a[j].y,a[i].x,a[i].y)%mod) %= mod;
		}
	}
	printf("%lld\n",dp[n+1]);

	return 0;
}

