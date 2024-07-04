// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1000003;

char s[55][55];
int C[105][105],n,k;

int popc(int x){
	int r = 0;
	while(x){r += x&1;x >>= 1;}
	return r;
}

void upd(int &x,int y){(x += y) %= mod;}

int vis[25], len, oc[505];
int calc(int S){
	for(int i=1;i<=len;i++)oc[i] = 0;
	for(int i=1;i<=n;i++){
		if(S & (1<<(i-1))){
			for(int j=1;j<=len;j++){
				if(s[i][j] == '?')continue;
				if(oc[j] && oc[j] != (int)s[i][j])return 0;
				oc[j] = (int)s[i][j];
			}
		}
	}
	int r = 1;
	for(int i=1;i<=len;i++)
		if(!oc[i])r = r * 26ll % mod;
	return r;
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%s",s[i] + 1);
	len = strlen(s[1] + 1);
	int res = 0;
	for(int S = 0; S<=(1<<n) -1 ;S++){
		int pc = popc(S);
		if(pc < k)continue;
		int fc = ((pc-k) & 1) ? -1 : 1;
		upd(res, 1ll * calc(S) * fc * C[pc][k] % mod);
		res = (mod + res) % mod; 
	}
	printf("%d\n",res);
}

signed main(){
	C[0][0] = 1;
	for(int i=1;i<=100;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

