// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, mod=1e9+7;

int f[305][305][305];
int n,l,r;

void upd(int &x,int y){(x += y) %= mod;}

signed main(){
	scanf("%lld%lld%lld",&n,&l,&r);
	f[1][1][1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=l;j++){
			for(int k=1;k<=r;k++){
				upd(f[i][j][k], 1ll * (i-2) * f[i-1][j][k]%mod + f[i-1][j-1][k] + f[i-1][j][k-1]);
			}
		}
	}
	printf("%lld\n",f[n][l][r]);

	return 0;
}


