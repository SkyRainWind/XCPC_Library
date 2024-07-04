// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

struct mat{
	int a[55][55];
	mat(){memset(a,0,sizeof a);}
}dp;
int n,mod,k,r;

mat operator * (mat a, mat b){
	mat c;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			for(int l=1;l<=k;l++)
				(c.a[i][j] += 1ll * a.a[i][l] * b.a[l][j] % mod) %= mod;
	return c;
}
mat ddp;

void pw(LL y){
	mat bs = dp;
	while(y){
		if(y&1)ddp = bs * ddp;
		bs = bs * bs;
		y >>= 1;
	}
}

signed main(){
	scanf("%d%d%d%d",&n,&mod,&k,&r);
	for(int i=2;i<=k;i++)
		dp.a[i][i-1] = dp.a[i][i] = 1;
	dp.a[1][1] = dp.a[1][k] = 1;
	if(k == 1)dp.a[1][1] = 2;
	ddp.a[1][1] = 1;
	
	pw(1ll * n*k);
	printf("%d\n",ddp.a[r+1][1]);

	return 0;
}

