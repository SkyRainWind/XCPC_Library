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

int n,k;
int a[2005];
int C[2005][2005];
int f[205][205], g[205][205];

void solve(){
	scanf("%d%d",&n,&k); 
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)f[i][j] = g[i][j] = 0;
	for(int i=1;i<=n;i++)f[i][1] = g[i][1] = 1;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++){
			int jj = j-1>0?j-1 : k;
			for(int ii=1;ii<i;ii++){
				if(j == 1 || a[ii] == a[i]){
					if(!f[ii][jj])continue;
					if(f[i][j] < f[ii][jj]+1){
						f[i][j] = f[ii][jj]+1;
						g[i][j] = g[ii][jj];
					}else if(f[i][j] == f[ii][jj] + 1){
						(g[i][j] += g[ii][jj]) %= mod;
					}
				}
			}
		}
	int mx=0,res=0;
	for(int i=1;i<=n;i++){
		if(mx < f[i][k]){
			mx = f[i][k];
			res = g[i][k];
		}else if(mx == f[i][k]){
			(res += g[i][k]) %= mod;
		}
	}
	if(mx == 0)puts("1");
	else printf("%d\n",res);
}

signed main(){
	C[0][0] = 1;
	for(int i=1;i<=2000;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)
			(C[i][j] = C[i-1][j] + C[i-1][j-1]) %= mod;
	}
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

