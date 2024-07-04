// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod=1e9+7,maxn=1e6+5;

int fac[maxn],inv[maxn],d[maxn];

int pw(int x,int y){
	if(!y)return 1;if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){
	if(!y)return 1;
	return 1ll*fac[x] * inv[x-y] %mod * inv[y]%mod;
}

signed main(){
	int te;scanf("%d",&te);
	fac[0] = inv[0] = 1;
	d[1] = 0, d[2] = 1;
	for(int i=3;i<=1000000;i++)d[i] = 1ll*(i-1)*(d[i-1] + d[i-2])%mod;
	for(int i=1;i<=1000000;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[1000000] = pw(fac[1000000], mod-2);
	for(int i=999999;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	while(te --){
		int n,m;scanf("%d%d",&n,&m);
		if(n == m)puts("1");
		else printf("%d\n",1ll*C(n,m)*d[n-m]%mod);
	}

	return 0;
}


