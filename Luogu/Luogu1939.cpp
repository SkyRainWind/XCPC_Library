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

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7;

struct mat{
	int a[5][5];
	mat(){memset(a,0,sizeof a);}
};

mat mul(mat a,mat b){
	mat c;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				(c.a[i][j] += 1ll*a.a[i][k]*b.a[k][j]%mod) %= mod;
	return c;
}

void solve(){
	LL n;scanf("%lld",&n);
	if(n <= 3){puts((n==1||n==2) ? "1" : "2");return ;}
	mat base,res;
	base.a[1][1] = base.a[1][2] = base.a[2][1] = base.a[3][2] = 1;
	res.a[1][1] = 2, res.a[2][1] = res.a[3][1] = 1;
	LL m = n-3;
	while(m){
		if(m&1)res = mul(base,res);
		base = mul(base,base);
		m >>= 1;
	}
	printf("%d\n",res.a[1][1]);
}

signed main(){
	solve();

	return 0;
}


