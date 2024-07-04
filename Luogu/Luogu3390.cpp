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

const int inf = 1e9, INF = 0x3f3f3f3f,mod=1e9+7;

int n;
LL k;
struct mat{
	int a[105][105];
	mat(){memset(a,0,sizeof a);}
}mt;

mat mul(mat a,mat b){
	mat c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				(c.a[i][j] += 1ll*a.a[i][k]*b.a[k][j]%mod)%=mod; 
	return c;
}

signed main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&mt.a[i][j]);
	mat bs = mt, res;
	for(int i=1;i<=n;i++)res.a[i][i] = 1;
	while(k){
		if(k&1)res = mul(res, bs);
		bs = mul(bs,bs);
		k >>= 1;
	}
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)printf("%d ",res.a[i][j]);

	return 0;
}


