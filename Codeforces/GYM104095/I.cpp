// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7, maxn=5e6+5;

/*
R2+r<R1 ? X

R1-r..R1+r
0..R2 交：[R1-r..R1+r] or [R1-r..R2]  -> [x..y]
pi*|y^2-x^2| / (pi * R2^2) = |y^2-x^2| / (R2^2)
t = (h-1)/a+1
一共 n 次，>= t 概率：C(n,t)*p^t*(1-p)^(n-t) + ...
*/

int pw(int x,int y){
	if(y==0)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int fac[maxn],inv[maxn];

int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}

void init(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=maxn-5;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[maxn-5]=pw(fac[maxn-5],mod-2);
	for(int i=maxn-6;i>=1;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}

int n,R1,R2,r,a,h,pp[maxn],qq[maxn];

signed main(){
	init();
	scanf("%d%d%d%d%d%d",&n,&R1,&R2,&r,&a,&h);
	if(R1+r >= R2)return puts("1"),0;
	int x1=max(0,R1-r), y1=R1+r;
	
	ll p = 1ll*y1*y1%mod;
	p = p*pw(1ll*R2*R2%mod,mod-2)%mod;
	
	pp[0]=qq[0]=1;
	for(int i=1;i<=n;i++)pp[i]=1ll*pp[i-1]*p%mod;
	for(int i=1;i<=n;i++)qq[i]=1ll*qq[i-1]*(1-p+mod)%mod;
	
	int t = (h-1)/a+1;
	if(t > n)return puts("0"), 0;
	
	int ans = 0;
	for(int i=t;i<=n;i++){
		(ans += 1ll*C(n,i)*pp[i]%mod*qq[n-i]%mod) %= mod;
	}
	printf("%d\n",ans);

	return 0;
}

